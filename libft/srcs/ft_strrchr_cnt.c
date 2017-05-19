#include "../../includes/libft.h"

int		ft_strrchr_cnt(char *s, char c)
{
	int 	cnt;

	cnt = ft_strlen(s);
	while (cnt > 0 && s[cnt] != c)
		cnt--;
	if (s[cnt] == c)
		return (cnt);
	return (-1);
}
