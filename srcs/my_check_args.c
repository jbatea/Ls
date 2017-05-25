#include "../includes/ft_ls.h"

size_t	my_mode(char *arg)
{
	struct	stat	sb;
	int		n;

	n = lstat(arg, &sb);
	if (!n && (S_ISREG(sb.st_mode) || S_ISDIR(sb.st_mode)\
	|| S_ISLNK(sb.st_mode)))
		return (1);
	return (0);
}

void	my_print_errors(t_ls *ls, char c, char *arg)
{
	ls->error.errors = ls->error.errors + 1;
	if (c == '-')
	{
		ft_printf("ft_ls: invalid option -- '%c'\n \
	Try './ft_ls --help' for more information.\n", ls->error.invalid);
		my_exit(ls, NULL);
	}
	else
		ft_printf("ft_ls: cannot access '%s': \
No such file or directory\n", arg);
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
		ret = (my_flags1(ls, tmp)) ? true : false;
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

void	my_check_args(int argc, char **argv, t_ls *ls)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if ((my_mode(argv[i])))
			my_add_files(ls, &(ls->queue), argv[i], ARG);
		else if (argv[i][0] == '-' && (my_flags1(ls, argv[i] + 1) ||\
		 my_split_arg(ls, argv[i] + 1)))
		{
			ls->error.flags = ls->error.flags + 1;
			ls->error.args = ls->error.args - 1;
		}
		else
			my_print_errors(ls, argv[i][0], argv[i]);
		i++;
	}
}
