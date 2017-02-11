#include "../includes/ft_ls.h"

char	*my_files(char *name, char *d_name)
{
	char	*tmp;
	char	*files;

	tmp = ft_strjoin(name, "/");
	files = ft_strjoin(tmp, d_name);
	ft_strdel(&tmp);
	return (files);
}

/*void	my_ls(t_ls *ls, char *name)
{
	struct dirent	*dirent;
	char	*files;
	DIR	*dir;

	if (!(dir = opendir(name)))
		my_add_files(ls, name, false);
	else
	{
		while ((dirent = readdir(dir)))
		{
			files = my_files(name, dirent->d_name);
			my_add_files(ls->files, files, false);
			dirent = NULL;
			ft_strdel(&files);
		}
		closedir(dir);
	}
}*/

void	my_save_files(t_ls *ls)
{
	my_sort(ls);
	my_print_files(ls, ls->files);
}
