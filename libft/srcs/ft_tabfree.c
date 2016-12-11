#include "../../includes/libft.h"

void	ft_tabfree(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}
