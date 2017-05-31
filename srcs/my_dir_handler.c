/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_dir_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:58:16 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/31 14:59:17 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			my_dir(t_files *files)
{
	int		i;
	int		ret;

	ret = -1;
	if (S_ISDIR(files->sb.st_mode))
	{
		i = ft_strrchr_cnt(files->name, '/') + 1;
		ret = (ft_strscmp(files->name + i, ".", "..") ?\
		DIRECTORY : -1);
	}
	return (ret);
}

void		my_check_dir(t_ls *ls)
{
	t_files *files;
	int		ret;

	my_reverse_list(&(ls->files));
	files = ls->files;
	while (files)
	{
		ret = my_dir(files);
		if (ret == DIRECTORY)
			my_add_top_files(&(ls->queue), files->name);
		files = files->next;
	}
	my_reverse_list(&(ls->files));
}

bool		my_hidden_file(t_ls *ls, char *name)
{
	if (ls->flags.ignore_backups && name[ft_strlen(name) - 1] == '~')
		return (false);
	if (name[0] != '.')
		return (true);
	if (name[0] == '.' && (ls->flags.all || ls->flags.directory))
		return (true);
	if (ft_strscmp(name, ".", "..") && name[0] == '.' &&\
		ls->flags.almost_all)
		return (true);
	return (false);
}

void		my_readdir(t_ls *ls, t_files *files)
{
	char			*path;
	struct dirent	*dirent;
	DIR				*dir;

	path = NULL;
	if (!(dir = opendir(files->name)))
		return ;
	if ((ls->flags.recursive || ls->error.args > 1))
		my_print_dir(ls, files);
	ls->d.size = 0;
	ls->d.gid = 0;
	ls->d.uid = 0;
	ls->d.lnk = 0;
	ls->d.blk = 0;
	while ((dirent = readdir(dir)))
	{
		if (my_hidden_file(ls, dirent->d_name))
		{
			path = my_files(ls, files->name, dirent->d_name);
			my_add_files(ls, &(ls->files), path, NOTARG);
			ft_strdel(&path);
		}
		dirent = NULL;
	}
	closedir(dir);
}

void		my_opendir(t_ls *ls, t_files *files)
{
	(files->type == DIRECTORY) ? my_readdir(ls, files) : 0;
	if (files->arg && files->type != DIRECTORY)
	{
		my_apply_flags(ls, files);
		ls->d.display++;
	}
}
