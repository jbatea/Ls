/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:20:32 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/31 16:09:31 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <sys/acl.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <errno.h>
# include <stdio.h>
# include <time.h>
# include <stdbool.h>
# include <sys/xattr.h>
# include "libft.h"

# define MALLOC		my_exit(ls, "Malloc Failed")

# define BUF_SIZE	100
# define SIX_MONTH	15768000
# define TIME_SIZE	13
# define RIGHT_SIZE	12

# define NOTARG		0
# define ARG		1

# define ERROR		0
# define DIRECTORY	1
# define REGULAR	2
# define LNK		3

typedef struct		s_flags
{
	bool			listing;
	bool			recursive;
	bool			reverse;
	bool			all;
	bool			time;
	bool			almost_all;
	bool			not_sort;
	bool			help;
	bool			ignore_backups;
	bool			no_group;
	bool			size;
	bool			file_size;
	bool			quote;
	bool			directory;
	bool			indicator_style;
}					t_flags;

typedef struct		s_display
{
	int				size;
	int				gid;
	int				uid;
	int				lnk;
	int				blk;
	int				display;

}					t_display;

typedef struct		s_files
{
	char			*name;
	char			time[TIME_SIZE];
	char			link[BUF_SIZE];
	char			right[RIGHT_SIZE];
	int				type;
	char			*dev;
	char			*sgid;
	char			*suid;
	struct stat		sb;
	bool			arg;
	t_display		d;
	struct s_files	*next;
}					t_files;

typedef struct		s_error
{
	int				args;
	int				flags;
	int				errors;
	char			invalid;
}					t_error;

typedef struct		s_ls
{
	t_error			error;
	t_flags			flags;
	t_files			*files;
	t_files			*queue;
	t_display		d;
}					t_ls;

t_files				*my_add_files(t_ls *ls, t_files **files,\
					char *name, bool arg);
t_files				*my_add_top_files(t_files **files,\
					char *name);
void				my_get_rights(t_files *files);
void				my_check_args(int argc, char **argv, t_ls *ls);
void				my_reverse_list(t_files **files);
void				my_reverse_ordered_list(t_files **files, long long int i);
void				my_del_files(t_files **files);
void				my_del_list(t_files **files);
void				my_print_files(t_ls *ls);
char				*my_files(t_ls *ls, char *name, char *d_name);
void				my_sort(t_ls *ls, t_files **files,\
					int (*cmp)(void *, void *));
void				my_exit(t_ls *ls, char *error);
void				my_opendir(t_ls *ls, t_files *files);
void				my_check_dir(t_ls *ls);
void				my_apply_flags(t_ls *ls, t_files *files);
bool				my_hidden_file(t_ls *ls, char *name);
void				my_print_total(t_ls *ls);
void				my_cmp(t_ls *ls, t_files **files, bool arg);
bool				my_flags1(t_ls *ls, char *arg);
int					my_timercmp(t_files *file1, t_files *file2);
int					my_sizercmp(t_files *file1, t_files *file2);
int					my_argrcmp(t_files *file1, t_files *file2);
int					my_arg_order(t_files *file1, t_files *file2);
void				my_print_dir(t_ls *ls, t_files *files);
int					my_filetype(t_files *files);
void				my_initright(t_files *files);
void				my_maj_display(t_ls *ls, t_files *new);
void				my_check_rdev(t_ls *ls, t_files *new);
void				my_listing(t_ls *ls, t_files *f, char *name);
int					my_check_father_right(t_files *files, char *name);
void				my_get_time(t_files *files);
void				my_check_link(t_files *files);

#endif
