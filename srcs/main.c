#include "../includes/ft_ls.h"

void	my_exit(t_ls *ls, char *error)
{
	(error) ? ft_printf("%s\n", error) : 0;
	(ls) ? my_del_list(&(ls->queue)) : 0;
	exit(EXIT_FAILURE);
}

void	my_help(t_ls *ls)
{
	ft_printf("\n			Ft_printf: Flags Description\n\n");
	ft_printf("-a, --all\n	do not ignore entries starting with .\n\n");
	ft_printf("-A, --almost-all\n	do not list implied . and ..\n\n");
	ft_printf("-B, --ignore-backups\n \
	do not list implied entries ending with ~\n\n");
	ft_printf("-d, --directory\n \
	list directories themselves, not their contents\n\n");
	ft_printf("-f\n	do not sort, enable -aU\n\n");
	ft_printf("-G, --no-group\n \
	in a long listing, don't print group names\n\n");
	ft_printf("-l, --listing\n	use a long listing format\n\n");
	ft_printf("-o\n	like -l, but do not list group information\n\n");
	ft_printf("-p, --indicator-style\n \
	append / indicator to directories\n\n");
	ft_printf("-Q, --quote-name\n \
	enclose entry names in double quotes\n\n");
	ft_printf("-r, --reverse\n	reverse order while sorting\n\n");
	ft_printf("-R, --recursive\n	list subdirectories recursively\n\n");
	ft_printf("-s, --size\n \
	print the allocated size of each file, in blocks\n\n");
	ft_printf("-S\n	sort by file size, largest first\n\n");
	ft_printf("-t, --time\n	sort by modification time, newest first\n\n");
	ft_printf("-U\n	do not sort; list entries in directory order\n\n");
	ft_printf("--help\n	display this help and exit\n\n");
	my_exit(ls, NULL);	
}

void	my_print_error(t_ls *ls)
{
	while (ls->queue && ls->queue->error)
	{
		ft_fprintf(2, "ft_ls: cannot open directory '%s': \
Permission denied\n", ls->queue->name);
		my_del_files(&(ls->queue));
	}
}

void	my_ls(t_ls *ls)
{
	my_print_error(ls);
	if (ls->queue && ls->queue->name)
	{
		if (!ls->flags.directory)
		{
			my_opendir(ls, ls->queue);
			my_del_files(&(ls->queue));
			(ls->flags.not_sort) ? 0 :\
			my_cmp(ls, &(ls->files), NOTARG);
			(ls->flags.recursive) ? my_check_dir(ls) : 0;
			(ls->flags.listing || ls->flags.size) ?\
			my_print_total(ls) : 0;
			my_print_files(ls);
		}
		else
		{
			my_apply_flags(ls, ls->queue);
			my_del_files(&(ls->queue));
		}
		my_ls(ls);
	}
}

int	main(int argc, char **argv)
{
	t_ls	ls;

	ft_bzero(&ls, sizeof(ls));
	ls.error.args = argc - 1;
	my_check_args(argc, argv, &ls);
	ls.flags.help ? my_help(&ls) : 0;
	(argc - 1) ? 0 : my_add_files(&ls, &(ls.queue), ".", NOTARG);
	if (argc - 1 == ls.error.flags + ls.error.errors && \
	(ls.error.errors != argc - 1))
		(ls.flags.help) ? 0 : my_add_files(&ls, &(ls.queue), ".", \
	NOTARG);
	(ls.flags.not_sort) ? 0 : my_cmp(&ls, &(ls.queue), ARG);
	my_ls(&ls);
	my_exit(&ls, NULL);
	return (0);
}
