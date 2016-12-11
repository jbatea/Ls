/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 16:47:56 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/16 14:04:52 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char			*ft_strjoin_free(char *s1, char *s2)
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
	ft_strdel(&s2);
	ft_strdel(&s1);
	return (scat);
}
