#include "../includes/ft_ls.h"

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

void	my_del_files(t_files **files)
{
	t_files *tmp;
	
	tmp = (*files)->next;
	ft_strdel(&((*files)->name));
	ft_strdel(&((*files)->dev));
	ft_memdel((void **)files);
	*files = tmp;
}

void	my_del_list(t_files **files)
{
	t_files *tmp;
	t_files *ptmp;

	tmp = *files;
	while (tmp)
	{
		ptmp = tmp->next;
		ft_strdel(&tmp->name);
		ft_memdel((void **)&tmp);
		tmp = ptmp;
	}
}

void	my_check_rdev(t_files *new)
{
	char	*major;
	char	*minor;
	char	*tmp;

	if (new->sb.st_rdev)
	{
		major = ft_itoa(MAJOR(new->sb.st_rdev));
		tmp = ft_strjoin(major, ", ");
		ft_strdel(&major);
		minor = ft_itoa(MINOR(new->sb.st_rdev));
		new->dev = ft_strjoin(tmp, minor);
		ft_strdel(&minor);
		ft_strdel(&tmp);
	}
	else
		new->dev = ft_itoa(new->sb.st_size);
	new->size = ft_strlen(new->dev);
}

t_files	*my_new_files(t_ls *ls, char *name, bool arg)
{
	t_files		*new;
	struct stat 	sb;
	char		*gid;
	char		*uid;

	new = (t_files *)malloc(sizeof(t_files));
	(!new) ? my_exit(NULL, "Malloc Failed") : 0;
	ft_bzero(new, sizeof(t_files));
	new->name = ft_strdup(name);
	new->arg = arg;
	if (!lstat(name, &sb))
	{
		new->sb = sb;
		my_check_rdev(new);
		new->blk = ft_count(sb.st_blocks / 2);
		(uid = getpwuid(sb.st_uid)->pw_name) ? (new->uid = (int)ft_strlen(uid)) : 0;
		(gid = getgrgid(sb.st_gid)->gr_name) ? (new->gid = (int)ft_strlen(gid)) : 0;
		new->lnk = ft_count(sb.st_nlink);
	}
	if (S_ISDIR(sb.st_mode) && ((S_IRGRP & sb.st_mode) != S_IRGRP))
		new->error = true;
	(ls && ls->size < new->size) ? (ls->size = new->size) : 0;
	(ls && ls->uid < new->uid) ? (ls->uid = new->uid) : 0;
	(ls && ls->gid < new->gid) ? (ls->gid = new->gid) : 0;
	(ls && ls->lnk < new->lnk) ? (ls->lnk = new->lnk) : 0;
	(ls && ls->blk < new->blk) ? (ls->blk = new->blk) : 0;
	return (new);
}

t_files	*my_add_files(t_ls *ls, t_files **files, char *name, bool arg)
{
	t_files	*new;
	t_files	*tmp;

	new = my_new_files(ls, name, arg);
	if (!*files)
		*files = new;
	else
	{
		tmp = (*files);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

t_files	*my_add_top_files(t_files **files, char *name)
{
	t_files	*new;
	t_files	*tmp;

	new = my_new_files(NULL, name, NOTARG);
	if (!*files)
		*files = new;
	else
	{
		tmp = (*files);
		new->next = tmp;
		(*files) = new;
	}
	return (new);
}
