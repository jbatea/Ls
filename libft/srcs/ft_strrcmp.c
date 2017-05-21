#include "../../includes/libft.h"

int			ft_strrcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (((unsigned char)s1[i] == (unsigned char)s2[i]) && s1[i])
		i++;
	return ((unsigned char)s2[i] - (unsigned char)s1[i]);
}

