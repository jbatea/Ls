#include "../includes/ft_ls.h"

int	my_argrcmp(t_files *file1, t_files *file2)
{
	int	i;

	if ((i = my_arg_order(file1, file2)))
		return (i);
	return (ft_strcmp(file2->name, file1->name));
}

int	my_sizercmp(t_files *file1, t_files *file2)
{
	int	i;

	if ((i = my_arg_order(file1, file2)))
		return (i);
	if ((i = file1->sb.st_size - file2->sb.st_size))
		return (i);
	return (ft_strcmp(file1->name, file2->name));
}

int	my_timercmp(t_files *file1, t_files *file2)
{
	int	i;

	if ((i = my_arg_order(file1, file2)))
		return (i);
	if ((i = file1->sb.st_mtime - file2->sb.st_mtime))
		return (i);
	if ((i = file1->sb.st_mtim.tv_nsec - file2->sb.st_mtim.tv_nsec))
		return (i);
	return (ft_strcmp(file2->name, file1->name));
}

