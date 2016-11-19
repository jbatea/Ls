/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snduporjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:39:31 by jbateau           #+#    #+#             */
/*   Updated: 2016/02/26 18:40:05 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_snduporjoin(char *s1, char *s2, int n)
{
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		tmp = ft_strndup(s2, n);
	else
		tmp = ft_strnjoin(s1, s2, n);
	return (tmp);
}
