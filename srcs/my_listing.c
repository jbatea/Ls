#include "../includes/ft_ls.h"

void	my_get_time(t_files *files)
{
	char	*tmp_time;
	time_t	dif;

	dif = time(NULL) - files->sb.st_mtime;
	tmp_time = ctime(&(files->sb.st_mtime));
	if (dif >= 0 && dif < SIX_MONTH)
		ft_strncpy(files->time, tmp_time + 4, 12);
	else
	{
		ft_strncpy(files->time + 7, tmp_time + 20, 4);
		ft_strncpy(files->time, tmp_time + 4, 7);
	}
}

void	my_check_link(t_files *files)
{
	if (S_ISLNK(files->sb.st_mode))
	{
		ft_strcpy(files->link, "-> ");
		readlink(files->name, files->link + 3, BUF_SIZE - 4);
	}
}

bool	my_group_and_size(t_ls *ls, t_files *f, char *name)
{
	if (ls->flags.no_group && !ls->flags.size && ls->flags.quote)
	{
		ft_printf("%s %*d %s %**s %s \"%s\"%s\n", f->right,\
		ls->lnk - f->lnk, f->sb.st_nlink, f->suid, ls->uid - f->uid,\
		ls->size - f->size, f->dev, f->time, name, f->link);
		return (true);
	}
	if (ls->flags.no_group && ls->flags.size && ls->flags.quote)
	{
		ft_printf("%*d %s %*d %s %**s %s \"%s\"%s\n", \
		ls->blk - f->blk, f->sb.st_blocks / 2, f->right,\
		 ls->lnk - f->lnk, f->sb.st_nlink, f->suid, ls->uid - f->uid,\
		 ls->size - f->size, f->dev, f->time, name, f->link);
		return (true);
	}
	if (ls->flags.no_group && ls->flags.size)
	{
		ft_printf("%*d %s %*d %s %**s %s %s %s\n", ls->blk - f->blk,\
		f->sb.st_blocks / 2, f->right, ls->lnk - f->lnk, \
		f->sb.st_nlink, f->suid, ls->uid - f->uid, ls->size - f->size,\
		 f->dev, f->time, name, f->link);
		return (true);
	}
	return (false);
}

void	my_size_and_quote(t_ls *ls, t_files *f, char *name)
{
	if (ls->flags.size && ls->flags.quote)
	{
		ft_printf("%*d %s %*d %s %*s %**s %s \"%s\"%s\n", \
		ls->blk - f->blk, f->sb.st_blocks / 2, f->right,\
		ls->lnk - f->lnk, f->sb.st_nlink, f->suid, ls->uid - f->uid,\
		f->sgid, ls->gid - f->gid, ls->size - f->size, f->dev,\
		f->time, name, f->link);
		return;
	}
	if (ls->flags.size)
	{
		ft_printf("%*d %s %*d %s %*s %**s %s %s %s\n",\
		ls->blk - f->blk, f->sb.st_blocks / 2, f->right,\
		ls->lnk - f->lnk, f->sb.st_nlink, f->suid, ls->uid - f->uid,\
		f->sgid, ls->gid- f->gid, ls->size - f->size, f->dev, f->time,\
		 name, f->link);
		return;
	}
	if (ls->flags.quote)
	{
		ft_printf("%s %*d %s %*s %**s %s \"%s\"%s\n", f->right,\
		ls->lnk - f->lnk, f->sb.st_nlink, f->suid, ls->uid - f->uid,\
		 f->sgid, ls->gid - f->gid, ls->size - f->size,\
		f->dev, f->time, name, f->link);
		return;
	}
}

void	my_listing(t_ls *ls, t_files *f, char *name)
{
	my_get_rights(f);
	my_get_time(f);
	my_check_link(f);
	f->suid = getpwuid(f->sb.st_uid)->pw_name;
	f->sgid = getgrgid(f->sb.st_gid)->gr_name;
	if (!ls->flags.no_group && !ls->flags.size && !ls->flags.quote)
	{
		ft_printf("%s %*d %s %*s %**s %s %s %s\n", f->right,\
		ls->lnk - f->lnk, f->sb.st_nlink, f->suid,\
		ls->uid - f->uid, f->sgid, ls->gid - f->gid,\
		ls->size - f->size, f->dev, f->time, name, f->link);
		return;
	}
	if (ls->flags.no_group && !ls->flags.size && !ls->flags.quote)
	{
		ft_printf("%s %*d %s %**s %s %s %s\n", f->right,\
		ls->lnk - f->lnk, f->sb.st_nlink, f->suid, ls->uid - f->uid,\
		ls->size - f->size, f->dev, f->time, name, f->link);
		return;
	}
	if (my_group_and_size(ls, f, name))
		return;
	my_size_and_quote(ls, f, name);
}
