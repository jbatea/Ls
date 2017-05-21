#include "../includes/ft_ls.h"

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

void	my_exit(t_ls *ls, char *error)
{
	(error) ? ft_printf("%s\n", error) : 0;
	(ls) ? my_del_list(&(ls->queue)) : 0;
	exit(EXIT_FAILURE);
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

