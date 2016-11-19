/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pacnull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 15:58:29 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/27 16:11:33 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pacnull(char *str, int len)
{
	while (len > 1)
	{
		str = ft_strjoin_free(str, ft_strdup(" "));
		len--;
	}
	return (str);
}
