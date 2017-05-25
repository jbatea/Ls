#include "../includes/ft_ls.h"

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
		if ((uid = getpwuid(sb.st_uid)->pw_name))
			new->uid = (int)ft_strlen(uid);
		if ((gid = getgrgid(sb.st_gid)->gr_name))
			new->gid = (int)ft_strlen(gid);
		new->lnk = ft_count(sb.st_nlink);
	}
	my_maj_display(ls, new);
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
