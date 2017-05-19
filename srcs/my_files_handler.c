#include "../includes/ft_ls.h"

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

void	my_del_files(t_files **files)
{
	t_files *tmp;
	
	tmp = (*files)->next;
	ft_strdel(&((*files)->name));
	ft_memdel((void **)files);
	*files = tmp;
}

t_files	*my_new_files(char *name)
{
	t_files	*new;


	new = (t_files *)malloc(sizeof(t_files));
	if (!new)
		my_exit("Malloc Failed");
	bzero(new, sizeof(t_files));
	new->name = ft_strdup(name);
	return (new);
}

t_files	*my_add_files(t_files **files, char *name)
{
	t_files	*new;
	t_files	*tmp;

	new = my_new_files(name);
	if (!*files)
		*files = new;
	else
	{
		tmp = (*files);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

t_files	*my_add_top_files(t_files **files, char *name)
{
	t_files	*new;
	t_files	*tmp;

	new = my_new_files(name);
	if (!*files)
		*files = new;
	else
	{
		tmp = (*files);
		new->next = tmp;
		(*files) = new;
	}
	return (new);
}
