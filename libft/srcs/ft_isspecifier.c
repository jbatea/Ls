/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspecifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 18:37:04 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/17 15:23:35 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isspecifier(int c)
{
	char	*str;

	str = "AaeEfFgGdiouxXcsCSDOUp%";
	if (ft_strchr_cnt(str, c) == -1)
		return (0);
	return (1);
}
