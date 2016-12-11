/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applysharp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:14:13 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/01 17:50:10 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_isxsharp(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && tmp[i] == '0')
		i++;
	if (tmp[i] && (tmp[i] == 'F' || tmp[i] == 'f'))
		return (1);
	return (0);
}

char	*ft_applysharp(char s, char *tmp, char f)
{
	if (f == '#' && tmp[0] && tmp[0] != '0')
	{
		if (s == 'x' || s == 'X' || s == 'o' || s == 'O')
			tmp = ft_strjoin_free(ft_sharpflag(s), tmp);
	}
	else if (f == '#' && tmp[0] && tmp[0] == '0' && ft_atoi(tmp))
	{
		if (s == 'x' || s == 'X' || s == 'o' || s == 'O')
			tmp = ft_strjoin_free(ft_sharpflag(s), tmp);
	}
	else if (f == '#' && ft_isxsharp(tmp))
	{
		if (s == 'x' || s == 'X' || s == 'o' || s == 'O')
			tmp = ft_strjoin_free(ft_sharpflag(s), tmp);
	}
	return (tmp);
}
