#include <stdio.h>
#include "../includes/ft_ls.h"

int	main(int argc, char **argv)
{
	t_ls	ls;

	my_check_args(argc, argv, &ls);
	printf("ls = %d\n", ls.flags.listing);
	return (0);
}
