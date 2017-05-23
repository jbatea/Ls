#include "../includes/ft_ls.h"
#include <stdio.h>

int	my_filetype(DIR **dir, char *name)
{
	struct stat 	sb;

	if (!lstat(name, &sb))
	{
		if (S_ISDIR(sb.st_mode) && (*dir = opendir(name)))
			return (DIRECTORY);
		if (S_ISDIR(sb.st_mode) && !(*dir))
			return (ERROR);
		if (S_ISLNK(sb.st_mode))
			return (LNK);
	}
	return (REGULAR);
}

int	my_dir(char *name)
{
	int	i;
	DIR	*dir;
	int	ret;

	dir = NULL;
	ret = my_filetype(&dir, name);
	if (ret == DIRECTORY)
	{
		i = ft_strrchr_cnt(name, '/') + 1;
		ret = (ft_strscmp(name + i, ".", "..") ? DIRECTORY : -1);
		closedir(dir);
	}
	return (ret);
}

void	my_check_dir(t_ls *ls)
{
	t_files *files;
	int	ret;


	my_reverse_list(&(ls->files));
	files = ls->files;
	while (files)
	{
		ret = my_dir(files->name);
		if (ret == DIRECTORY || ret == ERROR)
			my_add_top_files(&(ls->queue), files->name);
		files = files->next;
	}
	my_reverse_list(&(ls->files));
}

void	my_print_dir(t_ls *ls, t_files *files)
{
	if (ls->display)
		ft_printf("\n");
	if (ls->flags.quote)
		ft_printf("\"%s\":\n", files->name);
	else
		ft_printf("%s:\n", files->name);
	ls->display++;
	ls->total = true;	
}

bool	my_hidden_file(t_ls *ls, char *name)
{
	if (name[0] == '.' && (ls->flags.all || ls->flags.directory))
		return (true);
	if (ft_strscmp(name, ".", "..") && name[0] == '.' && ls->flags.almost_all)
		return (true);
	if (name[ft_strlen(name) - 1] == '~' && ls->flags.ignore_backups)
		return (false);
	if (name[0] != '.')
		return (true);
	return (false);
}

void	my_readdir(t_ls *ls, t_files *files, DIR *dir)
{
	char		*path;
	struct dirent	*dirent;

	path = NULL;
	((ls->flags.recursive || ls->error.args) && !ls->flags.directory) ? my_print_dir(ls, files) : 0;
	while ((dirent = readdir(dir)))
	{
		if (my_hidden_file(ls, dirent->d_name))
		{
			path = my_files(files->name, dirent->d_name);
			my_add_files(&files, path, NOTARG);
			ft_strdel(&path);
		}
		dirent = NULL;
	}
	closedir(dir);

}

void	my_opendir(t_ls *ls, t_files *files)
{
	DIR		*dir;
	int		ret;

	dir = NULL;
	ret = my_filetype(&dir, files->name);
	(ret == DIRECTORY) ? my_readdir(ls, files, dir) : 0;
	if (files->arg && ret != DIRECTORY)
	{
		my_apply_flags(ls, files);
		ls->display++;
	}
}
