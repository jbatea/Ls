#include "../../includes/libft.h"

int	ft_strscmp(char *str, char *cmp1, char *cmp2)
{
	if (!ft_strcmp(str, cmp1) || !ft_strcmp(str, cmp2))
		return (0);
	return (1);
}
