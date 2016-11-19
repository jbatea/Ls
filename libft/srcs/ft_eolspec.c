/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eolspec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:05:44 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/29 15:43:36 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_lastcharback(char *tmp)
{
	int		len;

	len = ft_strlen(tmp) - 1;
	while (len > 0 && tmp[len] == '\n')
		len--;
	if (ft_isspecifier(tmp[len]))
		return (1);
	return (0);
}

int			ft_eolspec(char *tmp)
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i + 1] == '\0')
		{
			if (ft_isspecifier(tmp[i]))
				return (1);
			if (ft_lastcharback(tmp))
				return (1);
		}
		i++;
	}
	return (0);
}
