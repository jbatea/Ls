#include "../includes/ft_ls.h"

char	*my_files(char *name, char *d_name)
{
	char	*tmp;
	char	*files;

	if (name[ft_strlen(name) - 1] != '/')
		tmp = ft_strjoin(name, "/");
	else
		tmp = ft_strdup(name);
	files = ft_strjoin(tmp, d_name);
	ft_strdel(&tmp);
	return (files);
}

void	my_del_files(t_files **files)
{
	t_files *tmp;
	
	tmp = (*files)->next;
	ft_strdel(&((*files)->name));
	ft_memdel((void **)files);
	*files = tmp;
}

void	my_del_list(t_files **files)
{
	t_files *tmp;
	t_files *ptmp;

	tmp = *files;
	while (tmp)
	{
		ptmp = tmp->next;
		ft_strdel(&tmp->name);
		ft_memdel((void **)&tmp);
		tmp = ptmp;
	}
}

t_files	*my_new_files(char *name, bool arg)
{
	t_files	*new;
	struct stat sb;


	new = (t_files *)malloc(sizeof(t_files));
	if (!new)
		my_exit(NULL, "Malloc Failed");
	bzero(new, sizeof(t_files));
	new->name = ft_strdup(name);
	new->arg = arg;
	if (!lstat(name, &sb))
		new->sb = sb;
	return (new);
}

t_files	*my_add_files(t_files **files, char *name, bool arg)
{
	t_files	*new;
	t_files	*tmp;

	new = my_new_files(name, arg);
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

	new = my_new_files(name, NOTARG);
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
