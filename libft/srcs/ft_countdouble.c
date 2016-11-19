/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:54:51 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/01 19:16:50 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_freetab(long long int *tab)
{
	int len;

	len = tab[0];
	free(tab);
	return (len);
}

int			ft_countdouble(double g)
{
	long long int	*tab;
	double			n2;
	int				len;

	tab = ft_initlongtab();
	if (g < 0)
	{
		tab[4] = -1;
		g = g * tab[4];
	}
	tab[3] = g;
	n2 = g;
	while ((n2 - tab[3]) > 0)
	{
		n2 = g * (ft_cnt(tab[1] + 1));
		tab[3] = n2;
		tab[1]++;
	}
	if (g < 1)
		tab[0]++;
	tab = ft_tablen(tab, g, n2);
	len = ft_freetab(tab);
	return (len);
}
