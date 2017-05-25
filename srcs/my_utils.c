#include "../includes/ft_ls.h"

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
	if (ls->display)
		ft_printf("\n");
	if (ls->flags.quote)
		ft_printf("\"%s\":\n", files->name);
	else
		ft_printf("%s:\n", files->name);
	ls->display++;
}

void	my_print_total(t_ls *ls)
{
	t_files	*tmp;
	int	total;

	tmp = ls->files;
	total = 0;
	while (tmp)
	{
		total = total + tmp->sb.st_blocks;
		tmp = tmp->next;
	}
	ft_printf("total %d\n", total / 2);
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

