/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:02:04 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/01 17:22:46 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_tmpcpy(char *tmp, char *str, int i, int j)
{
	while (tmp[j])
	{
		str[i] = tmp[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(tmp);
	tmp = ft_strdup_free(str);
	return (tmp);
}

char		*ft_fillflag(char *tmp, int len)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	if (len < (int)ft_strlen(tmp))
		return (tmp);
	if (len >= (int)ft_strlen(tmp))
		str = ft_strnew(len + 1);
	if (!str)
		return (NULL);
	if (tmp[i] == '-')
	{
		str[i] = '-';
		i++;
		j++;
	}
	while (len-- > (int)ft_strlen(tmp))
	{
		str[i] = '0';
		i++;
	}
	return (ft_tmpcpy(tmp, str, i, j));
}
