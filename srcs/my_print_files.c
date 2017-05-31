/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_print_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:56:25 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/31 15:56:58 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	my_opt_flags(t_ls *ls, t_files *files, char *name)
{
	if (ls->flags.listing)
		my_listing(ls, files, name);
	else if (ls->flags.size && !ls->flags.listing && !ls->flags.quote)
		ft_printf("%*d   %s\n", ls->d.blk - files->d.blk,\
		files->sb.st_blocks / 2, name);
	else if (ls->flags.size && ls->flags.quote && !ls->flags.listing)
		ft_printf("%*d  \"%s\"\n", ls->d.blk - files->d.blk,\
		files->sb.st_blocks / 2, name);
	else if (ls->flags.quote)
		ft_printf("\"%s\"\n", name);
	else
		ft_printf("%s\n", name);
}

void	my_apply_flags(t_ls *ls, t_files *files)
{
	char	*name;
	int		i;

	i = 0;
	if (!ls->flags.directory && (name = ft_strrchr(files->name, '/')))
		name = name + 1;
	else
		name = files->name;
	if (ls->flags.indicator_style && S_ISDIR(files->sb.st_mode))
	{
		i = 1;
		(name = ft_strjoin(name, "/")) ? 0 : MALLOC;
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
