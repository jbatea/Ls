/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:07:28 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/26 17:48:28 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_lststrlen(t_lst *lst)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = lst->next;
	while (tmp)
	{
		if (tmp->cpy)
			i = ft_strlen(tmp->cpy) + i;
		if (tmp->len)
			i++;
		tmp = tmp->next;
	}
	return (i);
}
