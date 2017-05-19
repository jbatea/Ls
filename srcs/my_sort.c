#include "../includes/ft_ls.h"

void	my_split_list(t_files *files, t_files **f1, t_files **f2)
{
	t_files *tmp;
	t_files *tmp2;

	if (!files || !files->next)
		*f2 = NULL;
	else
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

t_files	*my_merge_list(t_files *f1, t_files *f2)
{
	t_files	*files;

	files = NULL;
	if (!f1)
		return (f2);
	else if (!f2)
		return (f1);
	if (ft_strcasecmp(f1->name, f2->name) <= 0)
	{
		files = f1;
		files->next = my_merge_list(f1->next, f2);
	}
	else
	{
		files = f2;
		files->next = my_merge_list(f1, f2->next);
	}
	return (files);
}

void	my_sort_asc(t_files **files)
{
	t_files *head;
	t_files *f1;
	t_files	*f2;

	head = *files;
	if (!head || !head->next)
		return;
	my_split_list(head, &f1, &f2);
	my_sort_asc(&f1);
	my_sort_asc(&f2);
	*files = my_merge_list(f1, f2);
}

void	my_sort(t_files **files)
{
	my_sort_asc(files);
}
