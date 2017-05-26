#include "../includes/ft_ls.h"
#include <stdio.h>

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

bool	my_hidden_file(t_ls *ls, char *name)
{
	if (name[0] != '.')
		return (true);
	if (name[0] == '.' && (ls->flags.all || ls->flags.directory))
		return (true);
	if (ft_strscmp(name, ".", "..") && name[0] == '.' &&\
		ls->flags.almost_all)
		return (true);
	if (ls->flags.ignore_backups && name[ft_strlen(name) - 1] == '~')
		return (false);
	return (false);
}

void	my_readdir(t_ls *ls, t_files *files, DIR *dir)
{
	char		*path;
	struct dirent	*dirent;

	path = NULL;
	if ((ls->flags.recursive || ls->error.args) && !ls->flags.directory)
		my_print_dir(ls, files);
	ls->size = 0;
	ls->gid = 0;
	ls->uid = 0;
	ls->lnk = 0;
	ls->blk = 0;
	while ((dirent = readdir(dir)))
	{
		if (my_hidden_file(ls, dirent->d_name))
		{
			path = my_files(ls, files->name, dirent->d_name);
			my_add_files(ls, &files, path, NOTARG);
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
