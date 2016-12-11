/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:15:25 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/16 14:15:48 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_strlower_free(char *str)
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
	ft_strdel(&str);
	return (tmp);
}
