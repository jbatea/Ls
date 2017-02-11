#include "../includes/ft_ls.h"

bool	my_cmp(t_files **tmp, t_files **swp)
{
	char	*str;

	str = NULL;
	if (!*swp || !*tmp || ft_strcmp((*swp)->name, (*tmp)->name) >= 0)
		return (false);
	str = (*tmp)->name;
	(*tmp)->name = (*swp)->name;
	(*swp)->name = str;
	return (true);
}

void	my_sort_ascii(t_ls *ls, t_files *files)
{
	t_files	*tmp;

	tmp = NULL;
	files->brother ? (tmp = files->brother) : (tmp = files->son);
	if (tmp && my_cmp(&files, &tmp))
		my_sort_ascii(ls, ls->files);
	else
	{
		files->brother ? my_sort_ascii(ls, files->brother) : 0;
		files->son ? my_sort_ascii(ls, files->son) : 0;
	}
}

void	my_sort(t_ls *ls)
{
	my_sort_ascii(ls, ls->files);
}
