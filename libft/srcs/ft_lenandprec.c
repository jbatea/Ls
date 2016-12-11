/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenandprec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:31:36 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/30 18:05:47 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_lenandprec(char *str, int *tab)
{
	if ((tab[1] = ft_lenchr(str)))
		str = ft_islennorm(str);
	if ((tab[0] = ft_precchr(str)) != -1)
		str = ft_precflag(str);
	return (str);
}
