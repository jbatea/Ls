/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenandzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 16:50:16 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/01 17:49:37 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_lenandzero(char s, char *tmp, int *tab, char f)
{
	if (tab[0] > 0 && f != '0' && f != ' ' && !ft_iss(s))
	{
		if (f == '#' && (s == 'o' || s == 'O') && ft_strlen(tmp) > 1)
			tab[0]--;
		if (tmp[0] == '-' && tab[6] == 0)
		{
			tab[6] = 1;
			tab[0]++;
		}
		tmp = ft_fillflag(tmp, tab[0]);
	}
	return (tmp);
}
