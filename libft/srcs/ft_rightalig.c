/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rightalig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:59:04 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/14 20:53:55 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_tmpcopy(char *str, char *tmp, int j, int i)
{
	while (tmp[j])
	{
		str[i] = tmp[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_rightalig(char *tmp, int len)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	if (len > (int)ft_strlen(tmp))
		str = ft_strnew(len + 1);
	if (str)
	{
		while (len > (int)ft_strlen(tmp))
		{
			str[i] = ' ';
			i++;
			len--;
		}
		str = ft_tmpcopy(str, tmp, j, i);
		free(tmp);
		tmp = ft_strdup_free(str);
	}
	return (tmp);
}
