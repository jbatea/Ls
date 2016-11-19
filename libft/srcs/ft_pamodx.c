/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pamodx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:59:30 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/30 19:12:09 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_lenmodo(unsigned long long u, int lenmod)
{
	if (lenmod == 1)
		return (ft_lltoo((unsigned long)u));
	if (lenmod == 2)
		return (ft_lltoo((unsigned long long)u));
	if (lenmod == 3)
		return (ft_lltoo((unsigned short)u));
	if (lenmod == 4)
		return (ft_lltoo((unsigned char)u));
	if (lenmod == 5)
		return (ft_lltoo((size_t)u));
	if (lenmod == 6)
		return (ft_lltoo((uintmax_t)u));
	return (NULL);
}

char				*ft_lenmodx(unsigned long long u, int lenmod, char c)
{
	char *s;

	s = NULL;
	if (lenmod == 1)
		s = ft_llitox((unsigned long)u);
	if (lenmod == 2)
		s = ft_llitox((unsigned long long)u);
	if (lenmod == 3)
		s = ft_llitox((unsigned short)u);
	if (lenmod == 4)
		s = ft_llitox((unsigned char)u);
	if (lenmod == 5)
		s = ft_llitox((size_t)u);
	if (lenmod == 6)
		s = ft_llitox((uintmax_t)u);
	if (c == 'x')
		s = ft_strlower_free(s);
	return (s);
}

char				*ft_lenmodu(unsigned long long u, int lenmod)
{
	if (lenmod == 1)
		return (ft_llutoa((unsigned long)u));
	if (lenmod == 2)
		return (ft_llutoa((unsigned long long)u));
	if (lenmod == 3)
		return (ft_llutoa((unsigned short)u));
	if (lenmod == 4)
		return (ft_llutoa((unsigned char)u));
	if (lenmod == 5)
		return (ft_llutoa((size_t)u));
	if (lenmod == 6)
		return (ft_llutoa((uintmax_t)u));
	return (NULL);
}

char				*ft_pamodx(va_list pa, int lenmod, int c)
{
	unsigned long long int	u;

	u = va_arg(pa, unsigned long long);
	if (c == 'u')
		return (ft_lenmodu(u, lenmod));
	if (c == 'x' || c == 'X')
		return (ft_lenmodx(u, lenmod, c));
	if (c == 'o')
		return (ft_lenmodo(u, lenmod));
	return (NULL);
}
