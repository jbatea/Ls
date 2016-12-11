/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenmod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:01:10 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/20 17:07:42 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_lenmod(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != 'l' && str[i] != 'h' && str[i] != 'j' &&
			str[i] != 'z')
		i++;
	if (str[i] == 'l')
	{
		if (str[i + 1] && str[i + 1] == 'l')
			return (2);
		return (1);
	}
	if (str[i] == 'h')
	{
		if (str[i + 1] && str[i + 1] == 'h')
			return (4);
		return (3);
	}
	if (str[i] == 'z')
		return (5);
	if (str[i] == 'j')
		return (6);
	return (0);
}
