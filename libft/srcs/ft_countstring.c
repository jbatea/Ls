/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:20:53 by jbateau           #+#    #+#             */
/*   Updated: 2015/12/14 11:46:48 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			ft_countstring(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j] == c && s[j] != '\0')
		j++;
	while (s[j])
	{
		if (c != s[j])
		{
			while (c != s[j] && s[j] != '\0')
				j++;
			i++;
		}
		else
			j++;
	}
	return (i);
}
