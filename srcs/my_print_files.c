#include "../includes/ft_ls.h"

void	my_opt_flags(t_ls *ls, t_files *files, char *name)
{
	if (ls->flags.size && !ls->flags.listing && !ls->flags.quote)
		ft_printf("%*d   %s\n", ls->blk - files->blk,\
		files->sb.st_blocks / 2, name);
	else if (ls->flags.size && ls->flags.quote && !ls->flags.listing)
		ft_printf("%*d  \"%s\"\n", ls->blk - files->blk,\
		files->sb.st_blocks / 2, name);
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
