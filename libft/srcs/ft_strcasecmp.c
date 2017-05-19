#include "../../includes/libft.h"

int			ft_strcasecmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && ((unsigned char)ft_tolower(s1[i]) == (unsigned char)ft_tolower(s2[i])))
		i++;
	return ((unsigned char)ft_tolower(s1[i]) - (unsigned char)ft_tolower(s2[i]));
}
