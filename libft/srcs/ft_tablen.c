/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:50:00 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/01 18:53:39 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	*ft_tablen(long long int *tab, double g, double n2)
{
	while (g > 1)
	{
		tab[0]++;
		g = g / 10;
	}
	tab[2] = tab[0];
	tab[0] = tab[0] + tab[1];
	tab[3] = n2;
	if (tab[4] == -1)
	{
		tab[0]++;
		tab[2]++;
	}
	return (tab);
}
