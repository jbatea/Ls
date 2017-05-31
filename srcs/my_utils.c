/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:00:07 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/31 16:10:38 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		my_check_father_right(t_files *f, char *name)
{
	if (f->sb.st_mtime)
	{
		my_get_time(f);
		f->suid = getpwuid(f->sb.st_uid)->pw_name;
		f->sgid = getgrgid(f->sb.st_gid)->gr_name;
		my_check_link(f);
	}
	else
	{
		ft_printf("%c????????? ? ? ? ?              ? %s\n",\
				f->right[0], name);
		return (1);
	}
	return (0);
}

void	my_initright(t_files *files)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		files->right[i] = '-';
		i++;
	}
	files->right[i] = ' ';
}

void	my_print_dir(t_ls *ls, t_files *files)
{
	if (ls->d.display)
		ft_printf("\n");
	if (ls->flags.quote)
		ft_printf("\"%s\":\n", files->name);
	else
		ft_printf("%s:\n", files->name);
	ls->d.display++;
}

void	my_print_total(t_ls *ls)
{
	t_files	*tmp;
	int		total;

	tmp = ls->files;
	total = 0;
	while (tmp)
	{
		total = total + tmp->sb.st_blocks;
		tmp = tmp->next;
	}
	ft_printf("total %d\n", total);
}

void	my_reverse_list(t_files **files)
{
	t_files *prev;
	t_files *cur;
	t_files *next;

	prev = NULL;
	cur = *files;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*files = prev;
}
