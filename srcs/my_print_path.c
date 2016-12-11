#include "../includes/ft_ls.h"

char	*my_get_time(char *ctime)
{
	char	*time;

	time = ft_strndup(ctime + 4, ft_strlen(ctime) - 13);
	time[0] = ft_tolower(time[0]);
	return (time);
}

void	my_listing(char *path, char *d_name)
{
	char	*time;
	char	*uid;
	char	*gid;
	char	*right;
	struct	stat	sb;

	if (!lstat(path, &sb))
	{
		right = my_get_rights(sb.st_mode);
		time = my_get_time(ctime(&sb.st_mtime));
		uid = getpwuid(sb.st_uid)->pw_name;
		gid = getgrgid(sb.st_gid)->gr_name;
		ft_printf("%s% 3d %s %s %5d %s %s\n", right, sb.st_nlink, uid, gid, sb.st_size, time, d_name);
		ft_strdel(&time);
		ft_strdel(&right);
	}
}

void	my_apply_flags(char *path, t_ls *ls)
{
	char *name;

	name = ft_strrchr(path, '/') + 1;
	if (name && (ls->flags.all || (name[0] != '.')))
		ls->flags.listing ? my_listing(path, name) : ft_printf("%s\n", name);
}



void	my_print_files(t_ls *ls)
{
	t_path *tmp;

	tmp = ls->path;
	while (tmp)
	{
		my_apply_flags(tmp->path, ls);
		tmp = tmp->next;
	}
}
