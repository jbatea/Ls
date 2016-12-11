/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newelem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:42:25 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/19 19:15:42 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void			ft_newelem(t_lst *lst, char *str)
{
	t_lst		*new;
	t_lst		*cur;

	cur = lst;
	new = (t_lst *)malloc(sizeof(t_lst));
	if (new)
	{
		new->cpy = str;
		new->len = 0;
		new->next = NULL;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}
