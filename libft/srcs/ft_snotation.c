/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 16:38:07 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/27 21:47:41 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_cp(char *str, int j)
{
	char	*cpy;
	int		i;

	cpy = NULL;
	i = j;
	cpy = ft_strnew(ft_strlen(str) - j);
	if (!cpy)
		return (NULL);
	j = 0;
	while (str[i])
	{
		if (str[i] == '.')
			i++;
		else
		{
			cpy[j] = str[i];
			i++;
			j++;
		}
	}
	cpy[j] = '\0';
	return (cpy);
}

char		*ft_tmp(int j, char *str)
{
	char	*tmp;
	char	*cpy;

	cpy = NULL;
	tmp = NULL;
	tmp = ft_strndup(str, j);
	tmp = ft_strjoin_free(tmp, ft_strdup("."));
	cpy = ft_cp(str, j);
	tmp = ft_strjoin_free(tmp, cpy);
	tmp = ft_strjoin_free(tmp, ft_strdup("E+"));
	return (tmp);
}

char		*ft_snotation(char *str)
{
	char	*tmp;
	int		j;
	int		i;
	int		cnt;

	i = 0;
	j = 1;
	cnt = 0;
	if (str[i] == '-')
		j++;
	while (str[i] && str[i] != '.')
		i++;
	cnt = i - 1;
	if (j == 2)
		cnt--;
	tmp = ft_tmp(j, str);
	if (cnt < 10)
		tmp = ft_strjoin_free(tmp, ft_strdup("0"));
	tmp = ft_strjoin_free(tmp, ft_itoa(cnt));
	ft_strdel(&str);
	str = ft_strdup_free(tmp);
	return (str);
}
