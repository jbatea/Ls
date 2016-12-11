/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:45:52 by jbateau           #+#    #+#             */
/*   Updated: 2016/02/26 18:46:14 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_isflag(int c)
{
	char	*flag;
	int		i;

	i = 0;
	flag = "#-+ lhjz.";
	while (flag[i])
	{
		if (flag[i] == c || ft_isdigit(c) == 1)
			return (1);
		i++;
	}
	return (0);
}
