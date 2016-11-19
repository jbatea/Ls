/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:39:29 by jbateau           #+#    #+#             */
/*   Updated: 2015/12/09 15:10:08 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	const char		*s1;
	char			*s2;

	i = 0;
	s1 = src;
	s2 = dst;
	while (i < n)
	{
		s2[i] = s1[i];
		if ((unsigned char)s1[i] == (unsigned char)c)
			return (s2 + (i + 1));
		i++;
	}
	return (NULL);
}
