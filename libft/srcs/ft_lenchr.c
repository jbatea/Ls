/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:56:25 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/27 20:18:18 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_retatoi(char *tmp, int i)
{
	int		j;
	int		sign;
	char	*str;

	sign = 1;
	j = 0;
	if (tmp[i] == '-' && sign == 0)
		sign = -1;
	if (tmp[i] == '-' && sign == 1)
		sign = 0;
	j = i + 1;
	while (tmp[j] && ft_isdigit(tmp[j]))
		j++;
	str = ft_strndup(tmp + i, j);
	if (sign == 0)
		sign = 1;
	i = ft_atoi(str) * sign;
	if (str)
	{
		ft_strdel(&str);
		return (i);
	}
	return (-1);
}

int			ft_lenchr(char *tmp)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (tmp[i] && (!ft_isdigit(tmp[i]) || tmp[i] == '0') && (tmp[i] != '-' ||
				(tmp[i + 1] && !ft_isdigit(tmp[i + 1]))) && tmp[i] != '+')
	{
		if (tmp[i] == '.')
			return (0);
		i++;
	}
	j = ft_retatoi(tmp, i);
	if (j != -1)
		return (j);
	return (-1);
}
