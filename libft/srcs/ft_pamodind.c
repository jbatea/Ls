/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pamodind.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:06:07 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/26 16:45:58 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_lenfourtosix(long long int u, int lenmod)
{
	char	*str;

	str = NULL;
	if (lenmod == 4)
		str = ft_lltoa((char)u);
	if (lenmod == 5)
		str = ft_lltoa((size_t)u);
	if (lenmod == 6)
		str = ft_lltoa((intmax_t)u);
	return (str);
}

char		*ft_pamodind(va_list pa, int lenmod)
{
	char			*str;
	long long int	u;

	str = NULL;
	u = va_arg(pa, long long int);
	if (lenmod == 1)
		str = ft_lltoa((long int)u);
	if (lenmod == 2)
		str = ft_lltoa(u);
	if (lenmod == 3)
		str = ft_ltoa((short)u);
	if (lenmod == 4 || lenmod == 5 || lenmod == 6)
		return (ft_lenfourtosix(u, lenmod));
	return (str);
}
