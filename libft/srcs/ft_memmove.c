/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:25:17 by jbateau           #+#    #+#             */
/*   Updated: 2015/12/16 13:52:07 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s1;
	unsigned char		*s2;

	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	if (dst > src)
		while (len--)
			s2[len] = s1[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
