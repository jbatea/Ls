/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initlongtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:49:23 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/29 13:49:46 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

long long int	*ft_initlongtab(void)
{
	long long int	*tab;
	int				i;

	i = 0;
	tab = (long long int *)malloc(sizeof(long long int) * 5);
	if (!tab)
		return (NULL);
	while (i < 4)
	{
		tab[i] = 0;
		i++;
	}
	tab[i] = 1;
	return (tab);
}
