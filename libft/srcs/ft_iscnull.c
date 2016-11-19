/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscnull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:35:31 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/28 17:15:00 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_iscnull(char *s, t_lst *lst, int *tab)
{
	s = ft_strdup("\0");
	if (tab[2])
	{
		ft_newelem(lst, ft_strdup((s = ft_pacnull(s, tab[2]))));
		tab[2] = 0;
		free(s);
		s = ft_strdup("");
	}
	else
		ft_newelem(lst, ft_strdup(""));
	ft_increaselen(lst);
	return (s);
}
