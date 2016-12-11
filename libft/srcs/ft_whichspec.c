/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whichspec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:35:30 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/01 14:09:53 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			ft_whichspec(char *tmp)
{
	int		i;

	i = ft_strchr_cnt(tmp, '%') + 1;
	while (tmp[i])
	{
		if (ft_isspecifier(tmp[i]))
			return (tmp[i]);
		i++;
	}
	return (0);
}
