#ifndef FT_LS_H
#define FT_LS_H
			/*Includes*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdbool.h>
#include "libft.h"
			/*Defines*/

#define st_atime st_atim.tv_sec
#define st_mtime st_mtim.tv_sec
#define st_ctime st_ctim.tv_sec

			/*Structures*/

typedef struct		s_flags
{
	bool		listing;
	bool		recursive;
	bool		reverse;
	bool		all;
	bool		time;

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
	t_info		info;
	struct s_files	*next;
}			t_files;

typedef struct		s_error
{
	int		args;
	int		flags;
	int		errors;
}			t_error;

typedef struct		s_ls
{
	t_error		error;
	t_flags		flags;
	t_files		*files;
	t_files		*queue;
}			t_ls;

t_files	*my_add_files(t_files **files, char *name);
t_files	*my_add_top_files(t_files **files, char *name);
char	*my_get_rights(int mode);
void	my_check_args(int argc, char **argv, t_ls *ls);
void	my_reverse_list(t_files **files);
void	my_del_files(t_files **files);
void	my_ls(t_ls *ls);
void	my_print_files(t_ls *ls);
void	my_sort(t_files **files);
void	my_exit(char *error);

#endif
