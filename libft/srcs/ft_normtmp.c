/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normtmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:06:42 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/16 14:07:07 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_normtmp(char *tmp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_strnew(ft_strlen(tmp) + 1);
	if (!str)
		return (NULL);
	while (tmp[j])
	{
		if (tmp[j] == '%')
			j++;
		else
		{
			str[i] = tmp[j];
			i++;
			j++;
		}
	}
	str[i] = '\0';
	free(tmp);
	tmp = ft_strdup_free(str);
	return (tmp);
}
