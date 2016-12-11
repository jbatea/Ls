/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patypefloat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 19:23:10 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/01 18:45:26 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_patypefloat(int c, int *tab, char *s)
{
	int		i;
	char	*cpy;

	i = 6;
	if ((c == 'f' || c == 'F') && tab[1] == 1)
		s = ft_doubleprec(s, i);
	if (ft_atoi(s) < 0)
		i++;
	if ((c == 'g' || c == 'G') && tab[1] == 1)
	{
		if (ft_ispoint(s, i))
		{
			cpy = ft_strjoin_free(ft_strndup(s, i),
					ft_strndup(s + i + 1, ft_strlen(s) - i));
			free(s);
			s = ft_strdup_free(cpy);
		}
		else
		{
			cpy = ft_strdup_free(s);
			s = ft_strndup(cpy, i - 1);
			ft_strdel(&cpy);
		}
	}
	return (s);
}
