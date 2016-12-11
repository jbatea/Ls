#include "../../includes/libft.h"

int	ft_intnchr(char *line)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	j = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	j = i;
	while (line[j] && ft_isdigit(line[j]))
		j++;
	str = ft_strndup(line + i, j - i);
	i = ft_atoi(str);
	ft_strdel(&str);
	return (i);
}

int	ft_intrchr(char *line)
{
	int	i;
	int	j;
	char	*str;

	i = ft_strlen(line) - 2;
	j = i;
	while (i > 0 && ft_isdigit(line[i]))
		i--;
	str = ft_strndup(line + i, j - i + 1);
	i = ft_atoi(str);
	ft_strdel(&str);
	return (i);
}

int	ft_intchr(char *line, int n)
{
	if (n == 1)
		return (ft_intrchr(line));
	else
		return (ft_intnchr(line));
}
