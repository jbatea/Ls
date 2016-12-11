/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharpflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:59:40 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/30 17:26:46 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_sharpflag(char spec)
{
	char	*str;

	if (spec == 'o' || spec == 'O')
	{
		if (!(str = ft_strnew(2)))
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
	}
	if (spec == 'x' || spec == 'X')
	{
		if (!(str = ft_strnew(3)))
			return (NULL);
		str[0] = '0';
		if (spec == 'X')
			str[1] = 'X';
		else
			str[1] = 'x';
		str[2] = '\0';
	}
	return (str);
}
