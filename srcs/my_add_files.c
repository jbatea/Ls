#include "../includes/ft_ls.h"

t_files	*my_new_files(char *name, bool arg)
{
	t_files	*new;


	new = (t_files *)malloc(sizeof(t_files));
	if (!new)
		my_exit("Malloc Failed");
	new->son = NULL;
	new->brother = NULL;
	new->name = ft_strdup(name);
	new->arg = arg;
	return (new);
}

void	my_add_files(t_files **files, char *name, bool arg)
{
	t_files	*new;
	t_files	*tmp;

	new = my_new_files(name, arg);
	if (!*files)
		*files = new;
	else if (!(*files)->son)
		(*files)->son = new;
	else
	{
		tmp = (*files)->son;
		while (tmp->brother)
			tmp = tmp->brother;
		tmp->brother = new;
	}
}
