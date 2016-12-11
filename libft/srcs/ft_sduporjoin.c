/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sduporjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:40:10 by jbateau           #+#    #+#             */
/*   Updated: 2016/02/26 18:40:34 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_sduporjoin(char *s1, char *s2)
{
	char	*tmp;

	tmp = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		tmp = ft_strdup(s2);
	else
		tmp = ft_strjoin(s1, s2);
	return (tmp);
}
