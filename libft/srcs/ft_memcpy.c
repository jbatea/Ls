/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:24:40 by jbateau           #+#    #+#             */
/*   Updated: 2015/12/11 13:54:18 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*s1;
	char		*s2;

	i = 0;
	s1 = src;
	s2 = dst;
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}
