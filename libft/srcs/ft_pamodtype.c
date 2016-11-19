/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pamodtype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:03:31 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/30 17:02:32 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_wcstos(wchar_t *wcs)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	while (wcs[i])
	{
		if (!str)
			str = ft_wctos(wcs[i]);
		else
			str = ft_strjoin_free(str, ft_wctos(wcs[i]));
		i++;
	}
	return (str);
}

char		*ft_pacs(va_list pa, t_lst *lst, int *tab)
{
	char	*s;
	wint_t	wc;

	s = NULL;
	wc = va_arg(pa, wint_t);
	if (!wc)
		return (ft_iscnull(s, lst, tab));
	s = ft_wctos((wchar_t)wc);
	return (s);
}

char		*ft_pamodtype(va_list pa, int c, t_lst *lst, int *tab)
{
	char	*s;
	wchar_t	*wcs;

	s = NULL;
	wcs = NULL;
	if ((c == 's' || c == 'c') && tab[0])
	{
		if (c == 's')
		{
			wcs = va_arg(pa, wchar_t *);
			if (!wcs)
				return (ft_strdup("(null)"));
			s = ft_wcstos(wcs);
		}
		else
			s = ft_pacs(pa, lst, tab);
	}
	if (c == 'd' || c == 'i')
		s = ft_pamodind(pa, tab[0]);
	if (c == 'x' || c == 'X' || c == 'u' || c == 'o')
		s = ft_pamodx(pa, tab[0], c);
	return (s);
}
