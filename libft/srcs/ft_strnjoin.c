/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:36:51 by jbateau           #+#    #+#             */
/*   Updated: 2016/02/26 18:37:35 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strnjoin(const char *s1, const char *s2, int n)
{
	char	*tmp;

	tmp = ft_strnew(n);
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp, s1);
	ft_strncpy(tmp + ft_strlen(s1), s2, n);
	return (tmp);
}
