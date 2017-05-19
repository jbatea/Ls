#include "../../includes/libft.h"

char	*ft_strlower(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(ft_strlen(str) + 1);
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		if (ft_isupper(str[i]))
			tmp[i] = str[i] + 32;
		else
			tmp[i] = str[i];
		i++;
	}
	return (tmp);
}
