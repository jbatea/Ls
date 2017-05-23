#include "../includes/ft_ls.h"

char	*my_get_time(char *ctime)
{
	char	*time;

	time = ft_strndup(ctime + 4, ft_strlen(ctime) - 13);
	time[0] = ft_tolower(time[0]);
	return (time);
}

char	*my_check_link(t_ls *ls, t_files *files)
{
	char *buf;

	if (S_ISLNK(files->sb.st_mode))
	{
		buf = ft_strnew(BUF_SIZE);
		ft_strcpy(buf, "-> ");
		(!buf) ? (my_exit(ls, "Malloc Failed")) : 0;
		readlink(files->name, buf + 3, BUF_SIZE - 4);
		return (buf);
	}
	return (ft_strdup(""));
}

void	my_listing(t_ls *ls, t_files *files, char *d_name)
{
	char		*right;
	char		*time;
	char		*uid;
	char		*gid;
	char		*link;

	right = my_get_rights(files);
	time = my_get_time(ctime(&(files->sb.st_mtime)));
	uid = getpwuid(files->sb.st_uid)->pw_name;
	gid = getgrgid(files->sb.st_gid)->gr_name;
	link = my_check_link(ls, files);
	if (ls->flags.no_group && !ls->flags.size && !ls->flags.quote)
		ft_printf("%s% 3d %-6s % 6d %s %s%-6s\n", right, files->sb.st_nlink, uid, files->sb.st_size, time, d_name, link);
	else if (ls->flags.no_group && !ls->flags.size && ls->flags.quote)
		ft_printf("%s% 3d %-6s % 6d %s \"%s\"%-6s\n", right, files->sb.st_nlink, uid, files->sb.st_size, time, d_name, link);
	else if (ls->flags.no_group && ls->flags.size && ls->flags.quote)
		ft_printf("%-5d%s% 3d %-6s % 6d %s \"%s\"%-6s\n", files->sb.st_blocks / 2, right, files->sb.st_nlink, uid, files->sb.st_size, time, d_name, link);
	else if (ls->flags.no_group && ls->flags.size)
		ft_printf("%-5d%s% 3d %-6s % 6d %s %s%-6s\n", files->sb.st_blocks / 2, right, files->sb.st_nlink, uid, files->sb.st_size, time, d_name, link);
	else if (ls->flags.size && ls->flags.quote)
		ft_printf("%-5d%s% 3d %-6s %-7s % 6d %s \"%s\"%-6s\n", files->sb.st_blocks / 2, right, files->sb.st_nlink, uid, gid, files->sb.st_size, time, d_name, link);
	else if (ls->flags.size)
		ft_printf("%-5d%s% 3d %-6s %-7s % 6d %s %s%-6s\n", files->sb.st_blocks / 2, right, files->sb.st_nlink, uid, gid, files->sb.st_size, time, d_name, link);
	else if (ls->flags.quote)
		ft_printf("%s% 3d %-6s %-7s % 6d %s \"%s\"%-6s\n", right, files->sb.st_nlink, uid, gid, files->sb.st_size, time, d_name, link);
	else
		ft_printf("%s% 3d %-6s %-7s % 6d %s %s %-6s\n", right, files->sb.st_nlink, uid, gid, files->sb.st_size, time, d_name, link);	
	ft_strdel(&time);
	ft_strdel(&right);
	ft_strdel(&link);
}

void	my_opt_flags(t_ls *ls, t_files *files, char *name)
{
	if (ls->flags.size && !ls->flags.listing && !ls->flags.quote)
		ft_printf("%-4d %s\n", files->sb.st_blocks / 2, name);
	else if (ls->flags.size && ls->flags.quote && !ls->flags.listing)
		ft_printf("%-4d \"%s\"\n", files->sb.st_blocks / 2, name);
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
