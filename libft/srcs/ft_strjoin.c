/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 18:37:14 by jbateau           #+#    #+#             */
/*   Updated: 2016/02/01 18:57:07 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*scat;
	int			i;
	int			j;

	i = 0;
	j = 0;
	scat = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (scat == NULL)
		return (NULL);
	while (s1[i])
	{
		scat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		scat[i] = s2[j];
		i++;
		j++;
	}
	scat[i] = '\0';
	return (scat);
}
