/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_files_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:59:24 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/31 14:59:42 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		my_filetype(t_files *files)
{
	DIR	*dir;

	dir = NULL;
	if (S_ISDIR(files->sb.st_mode) && (dir = opendir(files->name)))
	{
		closedir(dir);
		return (DIRECTORY);
	}
	if (S_ISDIR(files->sb.st_mode) && !dir)
		return (ERROR);
	if (S_ISLNK(files->sb.st_mode))
		return (LNK);
	return (REGULAR);
}

char	*my_files(t_ls *ls, char *name, char *d_name)
{
	char	*tmp;
	char	*files;

	if (name[ft_strlen(name) - 1] != '/')
		(tmp = ft_strjoin(name, "/")) ? 0 : MALLOC;
	else
		(tmp = ft_strdup(name)) ? 0 : MALLOC;
	(files = ft_strjoin(tmp, d_name)) ? 0 : MALLOC;
	ft_strdel(&tmp);
	return (files);
}

void	my_check_rdev(t_ls *ls, t_files *new)
{
	char	*major;
	char	*minor;
	char	*tmp;

	if (new->sb.st_rdev)
	{
		(major = ft_itoa(major(new->sb.st_rdev))) ? 0 : MALLOC;
		(tmp = ft_strjoin(major, ", ")) ? 0 : MALLOC;
		ft_strdel(&major);
		(minor = ft_itoa(minor(new->sb.st_rdev))) ? 0 : MALLOC;
		(new->dev = ft_strjoin(tmp, minor)) ? 0 : MALLOC;
		ft_strdel(&minor);
		ft_strdel(&tmp);
	}
	else
		(new->dev = ft_itoa(new->sb.st_size)) ? 0 : MALLOC;
	new->d.size = ft_strlen(new->dev);
}

void	my_maj_display(t_ls *ls, t_files *new)
{
	if (ls)
	{
		(ls->d.size < new->d.size) ? (ls->d.size = new->d.size) : 0;
		(ls->d.uid < new->d.uid) ? (ls->d.uid = new->d.uid) : 0;
		(ls->d.gid < new->d.gid) ? (ls->d.gid = new->d.gid) : 0;
		(ls->d.lnk < new->d.lnk) ? (ls->d.lnk = new->d.lnk) : 0;
		(ls->d.blk < new->d.blk) ? (ls->d.blk = new->d.blk) : 0;
	}
}
