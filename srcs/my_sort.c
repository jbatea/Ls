#include "../includes/ft_ls.h"

void	my_split_list(t_files *files, t_files **f1, t_files **f2)
{
	t_files *tmp;
	t_files *tmp2;

	*f2 = NULL;
	if (files && files->next)
	{
		tmp = files->next;
		tmp2 = files;
		while (tmp)
		{
			tmp = tmp->next;
			if (tmp)
			{
				tmp = tmp->next;
				tmp2 = tmp2->next;
			}
		}
		*f2 = tmp2->next;
		tmp2->next = NULL;
	}
	*f1 = files;
}

t_files	*my_merge_list(t_ls *ls, t_files *f1, t_files *f2, int (*cmp)(void *, void *))
{
	t_files	*files;

	files = NULL;
	if (!f1)
		return (f2);
	else if (!f2)
		return (f1);
	if (cmp((void *)f1, (void *)f2) <= 0)
	{
		files = f1;
		files->next = my_merge_list(ls, f1->next, f2, cmp);
	}
	else
	{
		files = f2;
		files->next = my_merge_list(ls, f1, f2->next, cmp);
	}
	return (files);
}

void	my_sort(t_ls *ls, t_files **files, int (*cmp)(void *, void *))
{
	t_files *head;
	t_files *f1;
	t_files	*f2;

	head = *files;
	if (!head || !head->next)
		return;
	my_split_list(head, &f1, &f2);
	my_sort(ls, &f1, cmp);
	my_sort(ls, &f2, cmp);
	*files = my_merge_list(ls, f1, f2, cmp);
}
