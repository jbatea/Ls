/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islenflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:04:00 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/16 14:04:28 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int				ft_islenflag(char c)
{
	char		*flag;
	int			i;

	flag = "hjlz";
	i = 0;
	while (flag[i])
	{
		if (flag[i] == c)
			return (1);
		i++;
	}
	return (0);
}
