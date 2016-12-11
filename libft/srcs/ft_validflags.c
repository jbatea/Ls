/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 16:59:31 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/16 14:21:07 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_validflags(char *str)
{
	int	i;

	i = 1;
	if (!ft_orderflags(str))
		return (0);
	while (str[i])
	{
		if (!ft_isflag(str[i]) && !ft_isspecifier(str[i]))
			return (0);
		if (ft_isspecifier(str[i]) && str[i + 1] != '\0')
			return (0);
		if (str[i + 1] == '\0' && !ft_isspecifier(str[i]))
			return (0);
		i++;
	}
	return (1);
}
