#include "../includes/ft_ls.h"

char	*my_get_time(char *ctime)
{
	char	*time;

	time = ft_strndup(ctime + 4, ft_strlen(ctime) - 13);
	time[0] = ft_tolower(time[0]);
	return (time);
}

void	my_listing(char *pathname)
{
	char	*time;
	char	*uid;
	char	*gid;
	char	*right;
	struct	stat	sb;

		uid = NULL;
		gid = NULL;
		right = NULL;
		stat(pathname, &sb);
		right = my_get_rights(sb.st_mode);
		time = my_get_time(ctime(&sb.st_mtime));
		if (getpwuid(sb.st_uid))
			uid = getpwuid(sb.st_uid)->pw_name;
		if (getgrgid(sb.st_gid))
			gid = getgrgid(sb.st_gid)->gr_name;
		time = my_get_time(ctime(&sb.st_mtime));
		ft_printf("%s% d %s %s %5d %s %s\n", right, sb.st_nlink, uid, gid, sb.st_size, time, pathname);
		ft_strdel(&time);
		ft_strdel(&right);
}

void	my_apply_flags(char *name, t_ls *ls)
{
	if (name && (ls->flags.all || (name[0] != '.')))
		ls->flags.listing ? my_listing(name) : ft_printf("%s\n", name);
}

void	my_display_dirent(t_ls *ls, char *name)
{
	DIR		*dir;
	struct dirent	*dirent;

	dir = opendir(name);
	if (dir && ls->nbargs > 1)
		ft_printf("\n%s:\n", name);
	else if (!dir)
		ft_printf("%s\n", name);
	while (dir && (dirent = readdir(dir)))
	{
		my_apply_flags(dirent->d_name, ls);
		dirent = NULL;
	}
	closedir(dir);
}


void	my_print_files(t_ls *ls)
{
	t_files *tmp;

	tmp = ls->files;
	while (tmp)
	{
		my_display_dirent(ls, tmp->name);
		tmp = tmp->next;
	}
}
