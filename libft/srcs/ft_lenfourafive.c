/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenfourafive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:07:41 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/07 17:15:50 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

long int			ft_lenfourafive(int lenmod, va_list pa)
{
	long long int u;

	u = 0;
	if (lenmod == 4)
	{
		u = va_arg(pa, long int);
		return (u);
	}
	if (lenmod == 5)
		u = va_arg(pa, size_t);
	return ((long int)u);
}
