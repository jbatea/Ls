/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbehaviour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:45:58 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/19 18:35:57 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_unbehaviour(long long int u, int c)
{
	if ((int)u < 0 && c == 'u')
		return (ft_lltoa(u));
	if (u == 9223372036854775807)
		return (ft_strdup("7FFFFFFFFFFFFFFF"));
	if ((unsigned long long int)u > 9223372036854775807)
		return (ft_strdup("8000000000000000"));
	if (u > 4294967295)
		return (ft_strdup("100000000"));
	if (u == 4294967295)
		return (ft_strdup("4294967295"));
	return (NULL);
}
