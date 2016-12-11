#include "../includes/ft_ls.h"

void	my_on(int *i, int *j)
{
	*i = 1;
	*j = 1;
}

size_t	my_mode(char *arg)
{
	struct	stat	sb;

	stat(arg, &sb);
	if ((S_ISREG(sb.st_mode) || S_ISDIR(sb.st_mode)))
		return (1);
	return (0);
}

size_t	my_flags(char *arg, t_ls *ls)
{
	int	n;

	n = 0;
	ft_strscmp(arg, "-l", "--listing") ? : my_on(&n , &ls->flags.listing);
	ft_strscmp(arg, "-R", "--recursive") ? : my_on(&n , &ls->flags.recursive);
	ft_strscmp(arg, "-r", "--reverse") ? : my_on(&n , &ls->flags.reverse);
	ft_strscmp(arg, "-a", "--all") ? : my_on(&n , &ls->flags.all);
	ft_strscmp(arg, "-t", "--time") ? : my_on(&n , &ls->flags.time);
	if (!n & !my_mode(arg))
	{
		ft_printf("ls: cannot access '%s': No such file or directory\n", arg);
		ls->nberrors = ls->nberrors + 1;
		ls->nbargs = ls->nbargs - 1;
	}
	if (n)
	{
		ls->nbflags = ls->nbflags + 1;
		ls->nbargs = ls->nbargs - 1;
	}
	return (n);
}

void	my_check_args(int argc, char **argv, t_ls *ls)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!my_flags(argv[i], ls) && my_mode(argv[i]))
			my_add_files(ls, argv[i]);
		i++;
	}
}
