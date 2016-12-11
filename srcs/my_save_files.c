#include "../includes/ft_ls.h"

char	*my_path(char *name, char *d_name)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin(name, "/");
	path = ft_strjoin(tmp, d_name);
	ft_strdel(&tmp);
	return (path);
}

void	my_add_path(t_ls *ls, char *path)
{
	t_path	*new;
	t_path	*tmp;

	new = (t_path *)malloc(sizeof(t_path));
	if (new)
	{
		tmp = ls->path;
		new->next = NULL;
		new->path = ft_strdup(path);
		if (!tmp)
			ls->path = new;
		else
		{	
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

void	my_display_dirent(t_ls *ls, char *name)
{
	DIR		*dir;
	struct dirent	*dirent;
	char	*path;

	if (!(dir = opendir(name)))
		ft_printf("%s\n", name);
	else
	{
		if (ls->nbargs > 1 || ls->flags.recursive)
			ft_printf("\n%s:\n", name);
		while ((dirent = readdir(dir)))

		{
			path = my_path(name, dirent->d_name);
			my_add_path(ls, path);
			if (ls->flags.recursive && dirent->d_name[0] != '.' && (DT_DIR & dirent->d_type))
				my_display_dirent(ls, path);
			dirent = NULL;
			ft_strdel(&path);
		}
		closedir(dir);
	}
}

void	my_save_files(t_ls *ls)
{
	t_files *tmp;

	tmp = ls->files;
	while (tmp)
	{
		my_display_dirent(ls, tmp->name);
		tmp = tmp->next;
	}
}
