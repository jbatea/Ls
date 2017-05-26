#include "../includes/ft_ls.h"

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
		(major = ft_itoa(MAJOR(new->sb.st_rdev))) ? 0 : MALLOC;
		(tmp = ft_strjoin(major, ", ")) ? 0 : MALLOC;
		ft_strdel(&major);
		(minor = ft_itoa(MINOR(new->sb.st_rdev))) ? 0 : MALLOC;
		(new->dev = ft_strjoin(tmp, minor)) ? 0 : MALLOC;
		ft_strdel(&minor);
		ft_strdel(&tmp);
	}
	else
		(new->dev = ft_itoa(new->sb.st_size)) ? 0 : MALLOC;
	new->size = ft_strlen(new->dev);
}

void	my_maj_display(t_ls *ls, t_files *new)
{
	if (ls)
	{
		(ls->size < new->size) ? (ls->size = new->size) : 0;
		(ls->uid < new->uid) ? (ls->uid = new->uid) : 0;
		(ls->gid < new->gid) ? (ls->gid = new->gid) : 0;
		(ls->lnk < new->lnk) ? (ls->lnk = new->lnk) : 0;
		(ls->blk < new->blk) ? (ls->blk = new->blk) : 0;
	}
	if (S_ISDIR(new->sb.st_mode) && ((S_IRGRP & new->sb.st_mode)\
	 != S_IRGRP))
		new->error = true;
}
