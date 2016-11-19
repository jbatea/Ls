#include "../includes/ft_ls.h"
#include <stdio.h>

char	*my_gettime(char *ctime)
{
	char	*time;

	time = ft_strndup(ctime + 4, ft_strlen(ctime) - 13);
	time[0] = ft_tolower(time[0]);
	return (time);
}

char	*my_initright()
{
	char 	*right;
	int	i;

	i = 0;
	right = (char *)malloc(sizeof(char) * (11));
	while (i < 10)
	{
		right[i] = '-';
		i++;
	}
	right[i] = '\0';
	return (right);
}

char	*my_getright(int mode)
{
	char	*right;

	right = my_initright();
	if (S_ISDIR(mode))
		right[0] = 'd';
	if (S_ISLNK(mode))
		right[0] = 'l';
	if (S_IRWXU & mode)
		ft_strncpy(right + 1, "rwx", 3);
	if (S_IRWXG & mode)
		ft_strncpy(right + 4, "rwx", 3);
	if (S_IRWXO & mode)
		ft_strncpy(right + 7, "rwx", 3);
	return (right);
}

void	ft_display_stat(char *pathname, struct stat sb)
{
	char	*time;
	char	*uid;
	char	*gid;
	char	*right;

	right = my_getright(sb.st_mode);
	time = my_gettime(ctime(&sb.st_mtime));
	uid = getpwuid(sb.st_uid)->pw_name;
	gid = getgrgid(sb.st_gid)->gr_name;
	ft_printf("%s% d %s %s %-5d %s %s\n", right, sb.st_nlink, uid, gid, sb.st_size, time, pathname);
	ft_strdel(&time);
}

void	ft_display_info(char *pathname)
{
	struct	stat	sb;

	if (pathname[0] != '.')
	{
		stat(pathname, &sb);
		ft_display_stat(pathname, sb);
	}
}

void	ft_display_dirent(char *pathname)
{
	DIR	*dir;
	struct dirent *dirent;

	dir = opendir(pathname);
	while ((dirent = readdir(dir)))
	{
		ft_display_info(dirent->d_name);
		dirent = NULL;
	}
	closedir(dir);
}

int	main(void)
{
	ft_display_dirent(".");

	return (0);
}
