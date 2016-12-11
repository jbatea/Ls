/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orderflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:04:21 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/16 15:06:20 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_orderflags(char *str)
{
	int		i;

	i = 1;
	while (str[i] && ft_basicflags(str[i]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] && str[i] == '.')
	{
		i++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (ft_isdigit(str[i]))
			i++;
	}
	while (str[i] && ft_islenflag(str[i]))
		i++;
	if (str[i] && ft_isspecifier(str[i]))
		return (1);
	return (0);
}
