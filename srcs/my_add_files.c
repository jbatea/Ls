#include "../includes/ft_ls.h"

void	my_add_files(t_ls *ls, char *name)
{
	t_files	*new;
	t_files	*tmp;

	new = (t_files *)malloc(sizeof(t_files));
	if (new)
	{
		tmp = ls->files;
		new->next = NULL;
		new->name = ft_strdup(name);
		if (!tmp)
			ls->files = new;
		else
		{	
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		};
	}
}
