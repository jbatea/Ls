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
	char		*nwame;
	char		*right;
	char		*uid;
	char		*gid;
	char		*time;
	int		size;
	int		link;
}			t_info;

typedef struct		s_files
{
	t_info		info;
	struct s_files	*next;
}			t_files;

typedef struct		s_ls
{
	t_flags		flags;
	t_files		files;
}			t_ls;

void	my_check_args(int argc, char **argv, t_ls *ls);

#endif
