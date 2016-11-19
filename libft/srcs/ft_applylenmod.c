/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applylenmod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 18:18:29 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/09 18:42:53 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_applylenmod(int c, long long int u)
{
	if (c == 'u' && u == 0)
		return (ft_strdup("0"));
	if (c == 'u' && u == USHRT_MAX)
		return (ft_strdup("65535"));
	return (NULL);
}
