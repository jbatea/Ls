#ifndef FT_LS_H
#define FT_LS_H
			/*Includes*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "libft.h"
			/*Defines*/

#define st_atime st_atim.tv_sec
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec

			/*Structures*/

typedef struct		s_flags
{
	int		listing;
	int		recursive;
	int		reverse;
	int		all;
	int		time;

}			t_flags;

typedef	struct		s_info
{
	char		*right;
	char		*uid;
	char		*gid;
	char		*time;
	int		size;
	int		link;
}			t_info;

typedef struct		s_files
{
	char		*name;
	struct s_files	*next;
}			t_files;

typedef struct		s_path
{
	char		*path;
	t_info		info;	
	struct s_path	*next;
}			t_path;

typedef struct		s_ls
{
	int		nbargs;
	int		nbflags;
	int		nberrors;
	t_flags		flags;
	t_files		*files;
	t_path		*path;
}			t_ls;

void	my_check_args(int argc, char **argv, t_ls *ls);
void	my_save_files(t_ls *ls);
char	*my_get_rights(int mode);
void	my_add_files(t_ls *ls, char *name);
void	my_print_files(t_ls *ls);

#endif
