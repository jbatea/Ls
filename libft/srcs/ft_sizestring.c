/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizestring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:23:50 by jbateau           #+#    #+#             */
/*   Updated: 2015/12/14 11:52:10 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			ft_sizestring(char const *str, char c, int *count)
{
	int		len;

	len = 0;
	while (str[*count] == c && str[*count] != '\0')
		(*count)++;
	while (str[*count] != c && str[*count] != '\0')
	{
		len++;
		(*count)++;
	}
	return (len);
}
