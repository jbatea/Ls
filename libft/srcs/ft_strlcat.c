/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:03:28 by jbateau           #+#    #+#             */
/*   Updated: 2015/12/04 15:40:43 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (size >= (dst_len + 1))
	{
		ft_strncat(dst, src, (size - dst_len - 1));
		return (dst_len + ft_strlen(src));
	}
	return (ft_strlen(src) + size);
}
