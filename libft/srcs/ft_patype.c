/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patype.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:40:39 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/01 18:46:22 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_pap(va_list pa)
{
	void	*p;
	char	*s;

	s = NULL;
	p = va_arg(pa, void *);
	if (!p)
		return (ft_strdup("0x0"));
	s = ft_litox((unsigned long)p);
	s = ft_strjoin_free(ft_strdup("0x"), ft_strlower_free(s));
	return (s);
}

char				*ft_pax(int c, va_list pa)
{
	long long int	u;
	char			*s;

	s = NULL;
	if (c == 'p')
		return (ft_pap(pa));
	u = va_arg(pa, long long int);
	if (c == 'u')
		return (ft_lltoa((unsigned int)u));
	if (c == 'o')
		s = ft_lltoo((unsigned int)u);
	if (c == 'x' || c == 'X')
		s = ft_litox((unsigned int)u);
	if (c == 'x')
		s = ft_strlower_free(s);
	return (s);
}

char				*ft_patype(va_list pa, int c, int *tab, t_lst *lst)
{
	char			*s;
	char			*str;

	s = NULL;
	str = NULL;
	if (ft_isupper(c) && c != 'X' && !ft_isbspec(c))
	{
		c = ft_tolower(c);
		tab[0] = 1;
	}
	if (tab[0] && c != '%' && c != 'p')
		return (ft_pamodtype(pa, c, lst, tab));
	if (c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'p')
		return (ft_pax(c, pa));
	s = ft_applypa(c, pa, lst, tab);
	if ((str = ft_patypefloat(c, tab, s)))
		return (str);
	return (s);
}
