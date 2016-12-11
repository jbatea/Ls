/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:44:58 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/23 19:09:01 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_lst			*ft_listinit(void)
{
	t_lst		*list;

	list = (t_lst *)malloc(sizeof(t_lst));
	if (!list)
		return (NULL);
	list->cpy = NULL;
	list->len = 0;
	list->next = NULL;
	return (list);
}
