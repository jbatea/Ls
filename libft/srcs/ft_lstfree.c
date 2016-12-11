/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:54:41 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/16 13:55:34 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		ft_lstfree(t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*ptmp;

	tmp = *lst;
	while (tmp)
	{
		free(tmp->cpy);
		ptmp = tmp->next;
		free(tmp);
		tmp = ptmp;
	}
	*lst = NULL;
}
