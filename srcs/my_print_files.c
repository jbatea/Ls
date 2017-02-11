#include "../includes/ft_ls.h"

char	*my_get_time(char *ctime)
{
	char	*time;

	time = ft_strndup(ctime + 4, ft_strlen(ctime) - 13);
	time[0] = ft_tolower(time[0]);
	return (time);
}

void	my_listing(char *files, char *d_name)
{
	char	*time;
	char	*uid;
	char	*gid;
	char	*right;
	struct	stat	sb;

	if (!lstat(files, &sb))
	{
		right = my_get_rights(sb.st_mode);
		time = my_get_time(ctime(&sb.st_mtime));
		uid = getpwuid(sb.st_uid)->pw_name;
		gid = getgrgid(sb.st_gid)->gr_name;
		ft_printf("%s% 3d %-6s %-7s % 6d %s %s\n", right, sb.st_nlink, uid, gid, sb.st_size, time, d_name);
		ft_strdel(&time);
		ft_strdel(&right);
	}
}

void	my_apply_flags(t_ls *ls, t_files *files)
{
	char *name;

	if (ft_strchr(files->name, '/') && !files->arg)
		name = ft_strrchr(files->name, '/') + 1;
	else
		name = files->name;
	if (name && (ls->flags.all || (name[0] != '.')))
		ls->flags.listing ? my_listing(files->name, name) : ft_printf("%s\n", name);
}

void	my_print_files(t_ls *ls, t_files *files)
{
	my_apply_flags(ls, files);
	files->brother ? my_print_files(ls, files->brother) : 0;
	files->son ? my_print_files(ls, files->son) : 0;
}
