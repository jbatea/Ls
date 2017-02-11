#include "../includes/ft_ls.h"

void	my_exit(char *error)
{
	if (error)
		ft_printf("%s\n", error);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_ls	ls;

	bzero(&ls, sizeof(ls));
	ls.error.args = argc - 1;
	my_check_args(argc, argv, &ls);
	if (argc - 1 == ls.error.flags + ls.error.errors)
		my_add_files(&(ls.files), ".", false);
	my_save_files(&ls);
	return (0);
}
