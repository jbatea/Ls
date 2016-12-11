/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:30:52 by jbateau           #+#    #+#             */
/*   Updated: 2015/11/26 17:00:32 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	while (s1[i] && i < n)
	{
		j = 0;
		while ((s1[i] == s2[j]) && s2[j] && i < n)
		{
			i++;
			j++;
		}
		i = i - j;
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
