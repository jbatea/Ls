/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leftalig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:09:35 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/27 20:30:34 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_leftalig(char *tmp, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (len < 0)
		len = -len;
	if (len > (int)ft_strlen(tmp))
	{
		if (!(str = ft_strnew(len + 1)))
			return (NULL);
		while (tmp[i])
		{
			str[i] = tmp[i];
			i++;
		}
		while (i < len)
		{
			str[i] = ' ';
			i++;
		}
		str[i] = '\0';
		free(tmp);
		tmp = ft_strdup_free(str);
	}
	return (tmp);
}
