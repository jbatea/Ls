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

void			ft_printlist(t_lst *lst, int fd)
{
	t_lst		*tmp;

	tmp = lst->next;
	while (tmp)
	{
		if (tmp->cpy)
			write(fd, tmp->cpy, ft_strlen(tmp->cpy));
		tmp = tmp->next;
	}
}
