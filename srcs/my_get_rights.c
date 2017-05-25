#include "../includes/ft_ls.h"

void	my_setread(t_files *files)
{
	if ((S_IRUSR & files->sb.st_mode) == S_IRUSR)
		ft_strncpy(files->right + 1, "r", 1);
	if ((S_IRGRP & files->sb.st_mode) == S_IRGRP)
		ft_strncpy(files->right + 4, "r", 1);
	if ((S_IROTH & files->sb.st_mode) == S_IROTH)
		ft_strncpy(files->right + 7, "r", 1);
}

void	my_setwrite(t_files *files)
{
	if ((S_IWUSR & files->sb.st_mode) == S_IWUSR)
		ft_strncpy(files->right + 2, "w", 1);
	if ((S_IWGRP & files->sb.st_mode) == S_IWGRP)
		ft_strncpy(files->right + 5, "w", 1);
	if ((S_IWOTH & files->sb.st_mode) == S_IWOTH)
		ft_strncpy(files->right + 8, "w", 1);
}

void	my_setexec(t_files *files)
{
	if ((S_IXUSR & files->sb.st_mode) == S_IXUSR)
		ft_strncpy(files->right + 3, "x", 1);
	if ((S_IXGRP & files->sb.st_mode) == S_IXGRP)
		ft_strncpy(files->right + 6, "x", 1);
	if ((S_IXOTH & files->sb.st_mode) == S_IXOTH)
		ft_strncpy(files->right + 9, "x", 1);
}

void	my_setstickybit(t_files *files)
{
	if ((S_ISVTX & files->sb.st_mode) != S_ISVTX)
		return;
	((S_IXOTH & files->sb.st_mode) == S_IXOTH) ?\
		ft_strncpy(files->right + 9, "t", 1)\
			: ft_strncpy(files->right + 9, "T", 1);
	if (S_ISDIR(files->sb.st_mode))
		return;
	((S_IXUSR & files->sb.st_mode) == S_IXUSR) ?\
		ft_strncpy(files->right + 3, "s", 1) :\
			ft_strncpy(files->right + 3, "S", 1);
	((S_IXGRP & files->sb.st_mode) == S_IXGRP) ?\
		ft_strncpy(files->right + 6, "s", 1) :\
			ft_strncpy(files->right + 6, "S", 1);
}

void	my_get_rights(t_files *files)
{ 
	my_initright(files);
	if (S_ISDIR(files->sb.st_mode))
		files->right[0] = 'd';
	if (S_ISLNK(files->sb.st_mode))
		files->right[0] = 'l';
	if (S_ISSOCK(files->sb.st_mode))
		files->right[0] = 's';
	if (S_ISFIFO(files->sb.st_mode))
		files->right[0] = 'p';
	if (S_ISBLK(files->sb.st_mode))
		files->right[0] = 'b';
	if (S_ISCHR(files->sb.st_mode))
		files->right[0] = 'c';
	my_setread(files);
	my_setwrite(files);
	my_setexec(files);
	my_setstickybit(files);
	if (listxattr(files->name, NULL, 0) > 0)
		ft_strncpy(files->right + 10, "@", 1);
	if (acl_get_file(files->name, 0x00000100))
		ft_strncpy(files->right + 10, "+", 1);
}
