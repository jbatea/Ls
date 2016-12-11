/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:28:29 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/16 14:05:39 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		*ft_memalloc(size_t size)
{
	void	*mem;

	mem = (void *)malloc(sizeof(size_t) * (size + 1));
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}
