/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:44:35 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/31 14:45:20 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			ft_strcasecmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && ((unsigned char)ft_tolower(s1[i]) ==\
				(unsigned char)ft_tolower(s2[i])))
		i++;
	return ((unsigned char)ft_tolower(s1[i]) -\
			(unsigned char)ft_tolower(s2[i]));
}
