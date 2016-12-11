#include "../includes/ft_ls.h"

void	my_init_ls(t_ls *ls, int argc)
{
	ls->nbargs = argc - 1;
	ls->nberrors = 0;
	ls->nbflags = 0;
	ls->files = NULL;
	ls->flags.listing = 0;
	ls->flags.recursive = 0;
	ls->flags.reverse = 0;
	ls->flags.all = 0;
	ls->flags.time = 0;
}

int	main(int argc, char **argv)
{
	t_ls	ls;

	my_init_ls(&ls, argc);
	my_check_args(argc, argv, &ls);
	if (argc - 1 == ls.nbflags + ls.nberrors)
		my_add_files(&ls, "."); 
	my_print_files(&ls);
	return (0);
}
