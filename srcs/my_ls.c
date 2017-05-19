#include "../includes/ft_ls.h"
#include <stdio.h>

char	*my_files(char *name, char *d_name)
{
	char	*tmp;
	char	*files;

	if (name[ft_strlen(name) - 1] != '/')
		tmp = ft_strjoin(name, "/");
	else
		tmp = ft_strdup(name);
	files = ft_strjoin(tmp, d_name);
	ft_strdel(&tmp);
	return (files);
}

DIR	*my_isdir(char *name)
{
	struct stat 	sb;
	DIR		*dir;

	dir = NULL;
	if (!lstat(name, &sb) && S_ISDIR(sb.st_mode))
	{
		if ((dir = opendir(name)))
			return (dir);
	}
	return (NULL);
}

bool	my_dir(char *name)
{
	int	i;
	DIR	*dir;
	bool	ret;

	dir = NULL;
	ret = false;
	if ((dir = my_isdir(name)))
	{
		i = ft_strrchr_cnt(name, '/') + 1;
		ret = (ft_strscmp(name + i, ".", "..") ? true : false);
		closedir(dir);
	}
	return (ret);
}

void	my_check_dir(t_ls *ls)
{
	t_files *files;


	my_reverse_list(&(ls->files));
	files = ls->files;
	while (files)
	{
		if (my_dir(files->name))
			my_add_top_files(&(ls->queue), files->name);
		files = files->next;
	}
	my_reverse_list(&(ls->files));
}

void	my_print_dir(t_files *files)
{
	static int cnt;

	if (cnt)
		ft_printf("\n");
	ft_printf("%s:\n", files->name);
	cnt++;	
}

void	my_opendir(t_ls *ls, t_files *files)
{
	DIR		*dir;
	struct dirent	*dirent;
	char		*path;

	dir = NULL;
	if ((dir = my_isdir(files->name)))
	{
		ls->flags.recursive ? my_print_dir(files) : 0;
		while ((dirent = readdir(dir)))
		{
			path = my_files(files->name, dirent->d_name);
			my_add_files(&files, path);
			//if (my_dir(path) && ls->flags.recursive)
			//	my_add_files(&(ls->queue), path);
			dirent = NULL;
			ft_strdel(&path);
		}
		closedir(dir);
	}
}

void	my_ls(t_ls *ls)
{
	if (ls->queue && ls->queue->name)
	{
		my_add_files(&(ls->files), ls->queue->name);
		my_del_files(&(ls->queue));
		my_opendir(ls, ls->files);
		my_del_files(&(ls->files));
		my_sort(&(ls->files));
		//my_sort(&(ls->queue));
		ls->flags.recursive ? my_check_dir(ls) : 0;
		my_print_files(ls);
		my_ls(ls);
	}
}
