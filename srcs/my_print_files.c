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

void	my_listing(t_ls *ls, t_files *f, char *name)
{
	char		*uid;
	char		*gid;

	my_get_rights(f);
	my_get_time(f);
	my_check_link(f);
	uid = getpwuid(f->sb.st_uid)->pw_name;
	gid = getgrgid(f->sb.st_gid)->gr_name;
	if (!ls->flags.no_group && !ls->flags.size && !ls->flags.quote)
		ft_printf("%s %*d %s %*s %**s %s %s %s\n", f->right, ls->lnk - f->lnk, f->sb.st_nlink, uid, ls->uid - f->uid, gid, ls->gid - f->gid, ls->size - f->size, f->dev, f->time, name, f->link);	
	else if (ls->flags.no_group && !ls->flags.size && !ls->flags.quote)
		ft_printf("%s %*d %s %**s %s %s %s\n", f->right, ls->lnk - f->lnk, f->sb.st_nlink, uid, ls->uid - f->uid, ls->size - f->size, f->dev, f->time, name, f->link);
	else if (ls->flags.no_group && !ls->flags.size && ls->flags.quote)
		ft_printf("%s %*d %s %**s %s \"%s\"%s\n", f->right, ls->lnk - f->lnk, f->sb.st_nlink, uid, ls->uid - f->uid, ls->size - f->size, f->dev, f->time, name, f->link);
	else if (ls->flags.no_group && ls->flags.size && ls->flags.quote)
		ft_printf("%*d %s %*d %s %**s %s \"%s\"%s\n", ls->blk - f->blk, f->sb.st_blocks / 2, f->right, ls->lnk - f->lnk, f->sb.st_nlink, uid, ls->uid - f->uid, ls->size - f->size, f->dev, f->time, name, f->link);
	else if (ls->flags.no_group && ls->flags.size)
		ft_printf("%*d %s %*d %s %**s %s %s %s\n", ls->blk - f->blk, f->sb.st_blocks / 2, f->right, ls->lnk - f->lnk, f->sb.st_nlink, uid, ls->uid - f->uid, ls->size - f->size, f->dev, f->time, name, f->link);
	else if (ls->flags.size && ls->flags.quote)
		ft_printf("%*d %s %*d %s %*s %**s %s \"%s\"%s\n", ls->blk - f->blk, f->sb.st_blocks / 2, f->right, ls->lnk - f->lnk, f->sb.st_nlink, uid, ls->uid - f->uid, gid, ls->gid - f->gid, ls->size - f->size, f->dev, f->time, name, f->link);
	else if (ls->flags.size)
		ft_printf("%*d %s %*d %s %*s %**s %s %s %s\n", ls->blk - f->blk, f->sb.st_blocks / 2, f->right, ls->lnk - f->lnk, f->sb.st_nlink, uid, ls->uid - f->uid, gid, ls->gid- f->gid, ls->size - f->size, f->dev, f->time, name, f->link);
	else if (ls->flags.quote)
		ft_printf("%s %*d %s %*s %**s %s \"%s\"%s\n", f->right, ls->lnk - f->lnk, f->sb.st_nlink, uid, ls->uid - f->uid, gid, ls->gid - f->gid, ls->size - f->size, f->dev, f->time, name, f->link);
}

void	my_opt_flags(t_ls *ls, t_files *files, char *name)
{
	if (ls->flags.size && !ls->flags.listing && !ls->flags.quote)
		ft_printf("%*d   %s\n", ls->blk - files->blk, files->sb.st_blocks / 2, name);
	else if (ls->flags.size && ls->flags.quote && !ls->flags.listing)
		ft_printf("%*d  \"%s\"\n", ls->blk - files->blk, files->sb.st_blocks / 2, name);
	else if (ls->flags.listing)
		my_listing(ls, files, name);
	else if (ls->flags.quote)
		ft_printf("\"%s\"\n", name);
	else
		ft_printf("%s\n", name);
}

void	my_apply_flags(t_ls *ls, t_files *files)
{
	char 	*name;
	int	i;

	i = 0;
	if (!ls->flags.directory && ft_strchr(files->name, '/'))
		name = ft_strrchr(files->name, '/') + 1;
	else
		name = files->name;
	if (ls->flags.indicator_style && S_ISDIR(files->sb.st_mode))
	{
		i = 1;
		name = ft_strjoin(name, "/");
	}
	if (name && my_hidden_file(ls, name))
		my_opt_flags(ls, files, name);
	i ? ft_strdel(&name) : 0;
}

void	my_print_files(t_ls *ls)
{
	if (ls->files)
	{
		my_apply_flags(ls, ls->files);
		my_del_files(&(ls->files));
		ls->files ? my_print_files(ls) : 0;
	}
}
