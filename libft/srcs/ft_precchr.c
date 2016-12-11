/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:03:00 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/05 19:30:23 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int				ft_preczero(char *str)
{
	int			i;

	i = 0;
	if (str[i] == '.' && str[i + 1] == '-')
		i++;
	if (str[i] && str[i + 1] && (str[i + 1] == '0' || !ft_isdigit(str[i + 1])))
		return (1);
	return (0);
}

int				ft_precchr(char *tmp)
{
	int			i;
	int			sign;
	char		*str;

	i = 1;
	sign = 1;
	str = NULL;
	while (tmp[i] && tmp[i] != '.')
		i++;
	if (tmp[i] && ft_preczero(tmp + i))
		return (-1);
	if (tmp[i] == '-')
		sign = -1;
	str = ft_strndup(tmp + i, ft_strlen(tmp) - i - 1);
	i = ft_atoi(str + 1) * sign;
	ft_strdel(&str);
	if (i < 0)
		i = 0;
	return (i);
}
