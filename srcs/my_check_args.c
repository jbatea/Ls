#include "../includes/ft_ls.h"

void	my_init_flags(t_ls *ls, char *arg)
{
	ls->flags.listing = ft_strscmp(arg, "-l", "--listing") ? 0 : 1;
	ls->flags.recursive = ft_strscmp(arg, "-R", "--recursive") ? 0 : 1;
	ls->flags.reverse = ft_strscmp(arg, "-r", "--reverse") ? 0 : 1;
	ls->flags.all = ft_strscmp(arg, "-a", "--all") ? 0 : 1;
	ls->flags.time = ft_strscmp(arg, "-t", "--time") ? 0 : 1;
}	

void	my_check_flags(int argc, char **argv, t_ls *ls)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		my_init_flags(ls, argv[i]);
		i++;
	}
}

void	my_check_args(int argc, char **argv, t_ls *ls)
{
	my_check_flags(argc, argv, ls);
}
