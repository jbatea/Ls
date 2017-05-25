#include "../includes/ft_ls.h"

size_t	my_mode(char *arg)
{
	struct	stat	sb;
	int		n;

	n = lstat(arg, &sb);
	if (!n && (S_ISREG(sb.st_mode) || S_ISDIR(sb.st_mode) || S_ISLNK(sb.st_mode)))
		return (1);
	return (0);
}

bool	my_flagscmp(char *arg, char *s1, char *s2, bool *flags)
{
	if (s1 && s2 && ft_strscmp(arg, s1, s2))
		return (false);
	else if (s1 && !s2 && ft_strcmp(arg, s1))
		return (false);
	*flags = true;
	return (true);
}

bool	my_flags_priority(t_ls *ls, char *arg)
{
	bool	ret;

	ret = false;
	if (!ft_strscmp(arg, "t", "-time"))
	{
		ls->flags.time = true;
		ls->flags.file_size = false;
		ls->flags.not_sort = false;
		ret = true;
	}
	if (!ft_strcmp(arg, "S"))
	{
		ls->flags.file_size = true;
		ls->flags.time = false;
		ls->flags.not_sort = false;
		ret = true;
	}
	if (!ft_strcmp(arg, "U"))
	{
		ls->flags.not_sort = true;
		ls->flags.reverse = false;
		ls->flags.time = false;
		ls->flags.file_size = false;
		ret = true;
	}
	if (!ft_strcmp(arg, "f"))
	{
		ls->flags.not_sort = true;
		ls->flags.all = true;
		ls->flags.listing = false;
		ls->flags.reverse = false;
		ls->flags.time = false;
		ls->flags.file_size = false;
		ret = true;
	}
	return (ret);
}

bool	my_flags(t_ls *ls, char *arg)
{
	bool	ret;

	ret = 0;
	my_flags_priority(ls, arg) ? (ret = 1) : 0;
	my_flagscmp(arg, "r", "-reverse", &ls->flags.reverse) ? (ret = 1) : 0;
	my_flagscmp(arg, "l", "-listing", &ls->flags.listing) ? (ret = 1) : 0;
	my_flagscmp(arg, "R", "-recursive", &ls->flags.recursive) ? (ret = 1) : 0;
	my_flagscmp(arg, "a", "-all", &ls->flags.all) ? (ret = 1) : 0;
	my_flagscmp(arg, "A", "-almost-all", &ls->flags.almost_all) ? (ret = 1) : 0;
	my_flagscmp(arg, "G", "-no-group", &ls->flags.no_group) ? (ret = 1) : 0;
	my_flagscmp(arg, "B", "-ignore-backups", &ls->flags.ignore_backups) ? (ret = 1) : 0;
	my_flagscmp(arg, "s", "-size", &ls->flags.size) ? (ret = 1) : 0;
	my_flagscmp(arg, "Q", "-quote-name", &ls->flags.quote) ? (ret = 1) : 0;
	my_flagscmp(arg, "p", "-indicator-style", &ls->flags.indicator_style) ? (ret = 1) : 0;
	my_flagscmp(arg, "d", "-directory", &ls->flags.directory) ? (ret = 1) : 0;
	my_flagscmp(arg, "-help", NULL, &ls->flags.help) ? (ret = 1) : 0;
	if (!ft_strcmp(arg, "o"))
	{
		ls->flags.listing = true;
		ls->flags.no_group = true;
		ret = 1;
	}
	return (ret);
}

bool	my_split_arg(t_ls *ls, char *arg)
{
	int	i;
	char	*tmp;
	bool	ret;

	i = 0;
	tmp = NULL;
	while (arg[i])
	{
		tmp = ft_strndup(arg + i, 1);
		ret = (my_flags(ls, tmp)) ? true : false;
		ft_strdel(&tmp);
		if (ret == false)
		{
			ls->error.invalid = arg[i];
			return (ret);
		}
		i++;
	}
	return (ret);
}

void	my_print_errors(t_ls *ls, char c, char *arg)
{
	ls->error.errors = ls->error.errors + 1;
	if (c == '-')
	{
		ft_printf("ft_ls: invalid option -- '%c'\nTry './ft_ls --help' for more information.\n", ls->error.invalid);
		my_exit(ls, NULL);
	}
	else
		ft_printf("ft_ls: cannot access '%s': No such file or directory\n", arg);
}

void	my_check_args(int argc, char **argv, t_ls *ls)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if ((my_mode(argv[i])))
			my_add_files(ls, &(ls->queue), argv[i], ARG);
		else if (argv[i][0] == '-' && (my_flags(ls, argv[i] + 1) || my_split_arg(ls, argv[i] + 1)))
		{
			ls->error.flags = ls->error.flags + 1;
			ls->error.args = ls->error.args - 1;
		}
		else
			my_print_errors(ls, argv[i][0], argv[i]);
		i++;
	}
}
