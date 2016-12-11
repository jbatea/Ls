/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 17:33:35 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/01 18:57:26 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char			*ft_filltab(long long int *tab, char *s)
{
	s[tab[0] + 1] = '\0';
	while (tab[0] >= 0)
	{
		if (tab[4] == -1 && tab[0] == 0)
			s[tab[0]] = '-';
		else if (tab[0] == tab[2])
			s[tab[0]] = '.';
		else
		{
			s[tab[0]] = (tab[3] % 10) + '0';
			tab[3] = tab[3] / 10;
		}
		tab[0]--;
	}
	return (s);
}

char			*ft_dtos(double g, char *s)
{
	long long int	*tab;
	double			n2;

	tab = ft_initlongtab();
	if (g < 0)
	{
		tab[4] = -1;
		g = g * tab[4];
	}
	tab[3] = g;
	n2 = (double)g;
	while ((n2 - (double)tab[3]) > 0)
	{
		n2 = g * (ft_cnt(tab[1] + 1));
		tab[3] = n2;
		tab[1]++;
	}
	if (g < 1)
		tab[0]++;
	tab = ft_tablen(tab, g, n2);
	s = ft_filltab(tab, s);
	free(tab);
	return (s);
}
