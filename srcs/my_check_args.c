#include "../includes/ft_ls.h"

void	my_on(bool *i, bool *j)
{
	*i = true;
	*j = true;
}

void	my_off(bool *i, bool *j, bool *k)
{
	*i = false;
	*j = false;
	*k = false;
}

void	my_count(int *i, int *j)
{
	*i = *i + 1;
	*j = *j - 1;
}

size_t	my_mode(char *arg)
{
	struct	stat	sb;
	int		n;

	n = lstat(arg, &sb);
	if (!n && (S_ISREG(sb.st_mode) || S_ISDIR(sb.st_mode)))
		return (1);
	return (0);
}

void	my_error(t_ls *ls, bool n, char *arg)
{
	if (!n && !my_mode(arg))
	{
		ft_printf("ls: cannot access '%s': No such file or directory\n", arg);
		my_count(&(ls->error.errors), &(ls->error.errors));
	}
	n ? my_count(&(ls->error.flags), &(ls->error.args)) : 0;
}

void	my_flags_priority(char *arg, t_ls *ls, bool *n)
{
	if (!ft_strscmp(arg, "-r", "--reverse"))
	{
		my_on(n , &ls->flags.reverse);
		my_off(&ls->flags.time, &ls->flags.file_size, &ls->flags.not_sort);
	}
	if (!ft_strscmp(arg, "-t", "--time"))
	{
	 	my_on(n , &ls->flags.time);
		my_off(&ls->flags.reverse, &ls->flags.file_size, &ls->flags.not_sort);
	}
	if (!ft_strcmp(arg, "-S"))
	{
		my_on(n, &ls->flags.file_size);
		my_off(&ls->flags.reverse, &ls->flags.time, &ls->flags.not_sort);
	}
	if (!ft_strcmp(arg, "-U"))
	{
		my_on(n, &ls->flags.not_sort);
		my_off(&ls->flags.reverse, &ls->flags.time, &ls->flags.file_size);
	}
	if (!ft_strcmp(arg, "-f"))
	{
		my_on(n, &ls->flags.not_sort);
		ls->flags.all = true;
		ls->flags.listing = false;
		my_off(&ls->flags.reverse, &ls->flags.time, &ls->flags.file_size);
	}

}

bool	my_flags(char *arg, t_ls *ls)
{
	bool	n;

	n = false;
	my_flags_priority(arg, ls, &n);
	ft_strscmp(arg, "-l", "--listing") ? : my_on(&n , &ls->flags.listing);
	ft_strscmp(arg, "-R", "--recursive") ? : my_on(&n , &ls->flags.recursive);
	ft_strscmp(arg, "-a", "--all") ? : my_on(&n , &ls->flags.all);
	ft_strscmp(arg, "-A", "--almost-all") ? : my_on(&n , &ls->flags.almost_all);
	ft_strscmp(arg, "-G", "--no-group") ? : my_on(&n , &ls->flags.no_group);
	ft_strscmp(arg, "-B", "--ignore-backups") ? : my_on(&n , &ls->flags.ignore_backups);
	ft_strcmp(arg, "--help") ? : my_on(&n , &ls->flags.help);
	ft_strscmp(arg, "-s", "--size") ? : my_on(&n , &ls->flags.size);
	ft_strscmp(arg, "-Q", "--quote-name") ? : my_on(&n , &ls->flags.quote);
	ft_strscmp(arg, "-p", "--indicator-style") ? : my_on(&n , &ls->flags.indicator_style);
	ft_strscmp(arg, "-d", "--directory") ? : my_on(&n , &ls->flags.directory);
	if (!ft_strcmp(arg, "-o"))
	{
		ls->flags.listing = 1;
		my_on(&n, &ls->flags.no_group);
	}
	my_error(ls, n, arg);
	return (n);
}

void	my_check_args(int argc, char **argv, t_ls *ls)
{
	int		i;

	i = 1;;

	while (i < argc)
	{
		if (!my_flags(argv[i], ls) && my_mode(argv[i]))
			my_add_files(&(ls->queue), argv[i], ARG);
		i++;
	}
}
