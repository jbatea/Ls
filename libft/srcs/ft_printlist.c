/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:06:27 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/26 17:48:24 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void			ft_printlist(t_lst *lst)
{
	t_lst		*tmp;

	tmp = lst->next;
	while (tmp)
	{
		if (tmp->cpy)
			ft_putstrnull(tmp->cpy, tmp->len);
		tmp = tmp->next;
	}
}
