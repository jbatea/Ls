/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applypa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 20:00:31 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/01 19:16:53 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char				*ft_paex(int c)
{
	char		*s;

	s = NULL;
	if (!(s = ft_strnew(2)))
		return (NULL);
	*s = c;
	s[1] = '\0';
	return (s);
}

char				*ft_pac(va_list pa, t_lst *lst, int *tab)
{
	char	*s;
	char	c;

	c = 0;
	s = NULL;
	if (lst)
		c = (char)va_arg(pa, int);
	if (!c)
		s = ft_iscnull(s, lst, tab);
	else
	{
		s = (char *)malloc(sizeof(char) * 2);
		if (!s)
			return (NULL);
		s[0] = c;
		s[1] = '\0';
	}
	return (s);
}

char				*ft_pabspec(va_list pa, int *tab, int c)
{
	double	g;
	char	*s;
	int		len;

	g = va_arg(pa, double);
	len = ft_countdouble(g);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s = ft_dtos(g, s);
	if ((c == 'g' || c == 'G') && ft_strlen(s) > 6)
	{
		s = ft_strndup(s, 6);
		ft_putstr("s = ");
		ft_putendl(s);
	}
	if (c == 'e' || c == 'E')
	{
		s = ft_snotation(s);
		if (tab[1] == 1)
			s = ft_dprecsci(s, 6);
		if (c == 'e')
			s = ft_strlower_free(s);
	}
	return (s);
}

char				*ft_applypa(int c, va_list pa, t_lst *lst, int *tab)
{
	char	*s;

	s = NULL;
	if (c == 's')
	{
		s = va_arg(pa, char *);
		if (!s)
			s = ft_strdup("(null)");
		else
			s = ft_strdup(s);
	}
	if (c == '%')
		s = ft_paex(c);
	if (c == 'd' || c == 'i')
		s = ft_itoa(va_arg(pa, int));
	if (c == 'c')
		s = ft_pac(pa, lst, tab);
	if (ft_isbspec(c))
		s = ft_pabspec(pa, tab, c);
	return (s);
}
