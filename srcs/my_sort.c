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

void	*my_cmpflags(t_ls *ls, t_files *files)
{
	if (ls->flags.time || ls->flags.file_size)
		return ((void *)files);
	return ((void *)files->name);
}

t_files	*my_merge_list(t_ls *ls, t_files *f1, t_files *f2, int (*cmp)(void *, void *))
{
	t_files	*files;

	files = NULL;
	if (!f1)
		return (f2);
	else if (!f2)
		return (f1);
	if (cmp(my_cmpflags(ls, f1), my_cmpflags(ls, f2)) <= 0)
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

void	my_sort_asc(t_ls *ls, t_files **files, int (*cmp)(void *, void *))
{
	t_files *head;
	t_files *f1;
	t_files	*f2;

	head = *files;
	if (!head || !head->next)
		return;
	my_split_list(head, &f1, &f2);
	my_sort_asc(ls, &f1, cmp);
	my_sort_asc(ls, &f2, cmp);
	*files = my_merge_list(ls, f1, f2, cmp);
}

int	my_timecmp(t_files *file1, t_files *file2)
{
	int	i;

	if ((i = file2->sb.st_mtime - file1->sb.st_mtime))
		return (i);
	return (ft_strcmp(file1->name, file2->name));
}

int	my_sizecmp(t_files *file1, t_files *file2)
{
	int	i;

	if ((i = file2->sb.st_size - file1->sb.st_size))
		return (i);
	return (ft_strcmp(file1->name, file2->name));
}

void	my_sort(t_ls *ls, t_files **files)
{
	int (*cmp)(void *, void *);

	if (ls->flags.reverse)
		cmp = (void *)&ft_strrcmp;
	else if (ls->flags.time)
		cmp = (void *)&my_timecmp;
	else if (ls->flags.file_size)
		cmp = (void *)my_sizecmp;
	else
		cmp = (void *)&ft_strcmp;
	my_sort_asc(ls, files, cmp);
}
