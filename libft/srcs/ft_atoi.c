/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:13:12 by jbateau           #+#    #+#             */
/*   Updated: 2015/12/14 16:18:06 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int			i;
	int			res;
	int			sign;
	char		*s;

	i = 0;
	res = 0;
	sign = 1;
	s = ft_strtrimall(str);
	if (s[i] == '-')
		sign = -sign;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
		{
			ft_strdel(&s);
			return (sign * res);
		}
		res = res * 10 + s[i] - '0';
		i++;
	}
	ft_strdel(&s);
	return (sign * res);
}
