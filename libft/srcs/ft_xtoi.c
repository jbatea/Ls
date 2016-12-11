/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:10:37 by jbateau           #+#    #+#             */
/*   Updated: 2016/02/21 17:11:11 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			ft_xtoi(const char *str)
{
	int		i;
	int		res;
	char	*s;

	i = 0;
	res = 0;
	s = ft_strtrimall(str);
	while (s[i])
	{
		if (ft_ishex(s[i]) == 0)
		{
			ft_strdel(&s);
			return (res);
		}
		if (s[i] < 58)
			res = res * 16 + s[i] - 48;
		else
			res = res * 16 + s[i] - 55;
		i++;
	}
	ft_strdel(&s);
	return (res);
}
