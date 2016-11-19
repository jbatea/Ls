/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:05:33 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/16 15:05:56 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_isstr(char *tmp)
{
	int		i;
	char	*str;

	str = NULL;
	i = ft_strchr_cnt(tmp, '%');
	if (i != -1 && i != 0)
		str = ft_strndup(tmp, i);
	return (str);
}
