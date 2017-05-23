#include "../includes/ft_ls.h"

int	my_arg_order(t_files *file1, t_files *file2)
{
	if (file1->arg && file2->arg)
	{
		if (S_ISREG(file1->sb.st_mode) && S_ISDIR(file2->sb.st_mode))
			return (-1);
		if (S_ISDIR(file1->sb.st_mode) && S_ISREG(file2->sb.st_mode))
			return (1);
	}
	return (0);
}

int	my_timecmp(t_files *file1, t_files *file2)
{
	int	i;

	if ((i = my_arg_order(file1, file2)))
		return (i);
	if ((i = file2->sb.st_mtime - file1->sb.st_mtime))
		return (i);
	if ((i = file2->sb.st_mtimespec.tv_nsec - file1->sb.st_mtimespec.tv_nsec))
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
	if ((i = file1->sb.st_mtimespec.tv_nsec - file2->sb.st_mtimespec.tv_nsec))
		return (i);
	return (ft_strcmp(file2->name, file1->name));
}

int	my_sizecmp(t_files *file1, t_files *file2)
{
	int	i;

	if ((i = my_arg_order(file1, file2)))
		return (i);
	if ((i = file2->sb.st_size - file1->sb.st_size))
		return (i);
	return (ft_strcmp(file1->name, file2->name));
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

int	my_argcmp(t_files *file1, t_files *file2)
{
	int	i;

	if ((i = my_arg_order(file1, file2)))
		return (i);
	return (ft_strcmp(file1->name, file2->name));
}

int	my_argrcmp(t_files *file1, t_files *file2)
{
	int	i;

	if ((i = my_arg_order(file1, file2)))
		return (i);
	return (ft_strcmp(file2->name, file1->name));
}


void	my_cmp(t_ls *ls, t_files **files, bool arg)
{
	int (*cmp)(void *, void *);

	if (ls->flags.time && ls->flags.reverse && arg)
		cmp = (void *)&my_timercmp;
	else if (ls->flags.time)
		cmp = (void *)&my_timecmp;
	else if (ls->flags.file_size && ls->flags.reverse && arg)
		cmp = (void *)my_sizercmp;
	else if (ls->flags.file_size)
		cmp = (void *)my_sizecmp;
	else if (ls->flags.reverse && arg)
		cmp = (void *)&my_argrcmp;
	else
		cmp = (void *)&my_argcmp;
	my_sort(ls, files, cmp);
	(ls->flags.reverse && !arg) ? my_reverse_list(files) : 0;
}
