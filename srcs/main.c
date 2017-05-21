#include "../includes/ft_ls.h"

void	my_help(t_ls *ls)
{
	ft_printf("\n			Ft_printf: Flags Description\n\n");
	ft_printf("-a, --all\ndo not ignore entries starting with .\n\n");
	ft_printf("-A, --almost-all\ndo not list implied . and ..\n\n");
	ft_printf("-B, --ignore-backups\ndo not list implied entries ending with ~\n\n");
	ft_printf("-d, --directory\nlist directories themselves, not their contents\n\n");
	ft_printf("-f\ndo not sort, enable -aU\n\n");
	ft_printf("-G, --no-group\nin a long listing, don't print group names\n\n");
	ft_printf("-l, --listing\nuse a long listing format\n\n");
	ft_printf("-o\nlike -l, but do not list group information\n\n");
	ft_printf("-p, --indicator-style\nappend / indicator to directories\n\n");
	ft_printf("-Q, --quote-name\nenclose entry names in double quotes\n\n");
	ft_printf("-r, --reverse\nreverse order while sorting\n\n");
	ft_printf("-R, --recursive\nlist subdirectories recursively\n\n");
	ft_printf("-s, --size\nprint the allocated size of each file, in blocks\n\n");
	ft_printf("-S\nsort by file size, largest first\n\n");
	ft_printf("-t, --time\nsort by modification time, newest first\n\n");
	ft_printf("-U\ndo not sort; list entries in directory order\n\n");
	ft_printf("--help\ndisplay this help and exit\n\n");
	my_exit(ls, NULL);
	
}

void	my_ls(t_ls *ls)
{
	if (ls->queue && ls->queue->name)
	{
		my_add_files(&(ls->files), ls->queue->name, ls->queue->arg);
		(ls->flags.directory) ? my_apply_flags(ls, ls->queue) : 0;
		my_del_files(&(ls->queue));
		my_opendir(ls, ls->files);
		my_del_files(&(ls->files));
		ls->flags.not_sort ? 0 : my_sort(ls, &(ls->files));
		(ls->flags.recursive && !ls->flags.directory) ? my_check_dir(ls) : 0;
		((ls->flags.listing || ls->flags.size) && !ls->flags.directory) ? my_print_total(ls) : 0;
		(ls->flags.directory) ? 0 : my_print_files(ls);
		my_ls(ls);
	}
}

int	main(int argc, char **argv)
{
	t_ls	ls;

	bzero(&ls, sizeof(ls));
	ls.error.args = argc - 1;
	my_check_args(argc, argv, &ls);
	ls.flags.help ? my_help(&ls) : 0;
	if (argc - 1 == ls.error.flags + ls.error.errors)
		(ls.flags.help) ? 0 : my_add_files(&(ls.queue), ".", NOTARG);
	ls.flags.not_sort ? 0 : my_sort(&ls, &(ls.queue));
	my_ls(&ls);
	return (0);
}
