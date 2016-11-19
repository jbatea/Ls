/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_speccnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:38:36 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/15 14:14:40 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_speccnt(const char *format)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			while (format[i] && ft_isspecifier(format[i]) == 0)
				i++;
			if (format[i])
				cnt++;
			else
				return (-1);
		}
		i++;
	}
	return (cnt);
}
