#include "../includes/ft_ls.h"

void	my_on(bool *i, bool *j)
{
	*i = true;
	*j = true;
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

bool	my_flags(char *arg, t_ls *ls)
{
	bool	n;

	n = false;
	ft_strscmp(arg, "-l", "--listing") ? : my_on(&n , &ls->flags.listing);
	ft_strscmp(arg, "-R", "--recursive") ? : my_on(&n , &ls->flags.recursive);
	ft_strscmp(arg, "-r", "--reverse") ? : my_on(&n , &ls->flags.reverse);
	ft_strscmp(arg, "-a", "--all") ? : my_on(&n , &ls->flags.all);
	ft_strscmp(arg, "-t", "--time") ? : my_on(&n , &ls->flags.time);
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
			my_add_files(&(ls->queue), argv[i]);
		i++;
	}
}
