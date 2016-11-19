/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:02:42 by jbateau           #+#    #+#             */
/*   Updated: 2015/11/26 14:23:11 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		s_len;

	s_len = ft_strlen(s);
	while (s_len > 0 && c != s[s_len])
		s_len--;
	if (c == s[s_len])
		return ((char *)s + s_len);
	else
		return (NULL);
}
