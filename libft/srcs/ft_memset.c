/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:23:43 by jbateau           #+#    #+#             */
/*   Updated: 2015/11/27 17:09:05 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*s;
	unsigned char	a;

	i = 0;
	s = b;
	a = c;
	while (i < len)
	{
		s[i] = a;
		i++;
	}
	return (s);
}
