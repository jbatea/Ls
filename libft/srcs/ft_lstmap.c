/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:31:53 by jbateau           #+#    #+#             */
/*   Updated: 2015/12/16 12:13:23 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lstnew;
	t_list	*tmp;

	lstnew = (t_list *)malloc(sizeof(t_list));
	if (lstnew == NULL)
		return (NULL);
	lstnew = (*f)(lst);
	tmp = lstnew;
	while (lst->next != NULL)
	{
		lst = lst->next;
		tmp->next = (*f)(lst);
		tmp = tmp->next;
	}
	return (lstnew);
}
