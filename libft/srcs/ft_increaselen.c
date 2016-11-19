/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increaselen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:12:40 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/26 17:44:12 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_increaselen(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->next)
			tmp = tmp->next;
		else
		{
			tmp->len = tmp->len + 1;
			return (1);
		}
	}
	return (0);
}
