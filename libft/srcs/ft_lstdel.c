/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 15:59:23 by jbateau           #+#    #+#             */
/*   Updated: 2015/12/12 11:42:23 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*ptmp;

	tmp = *alst;
	while (tmp != NULL)
	{
		del(tmp->content, tmp->content_size);
		ptmp = tmp->next;
		free(tmp);
		tmp = ptmp;
	}
	*alst = NULL;
}
