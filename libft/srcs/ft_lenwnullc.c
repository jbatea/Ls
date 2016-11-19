/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenwnullc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 18:16:53 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/27 16:30:49 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_lenwnullc(int *tab)
{
	char	*str;

	str = NULL;
	while (tab[0] > 1)
	{
		if (!str)
			str = ft_strdup("");
		else
			str = ft_strjoin_free(str, ft_strdup(""));
		tab[0]--;
	}
	return (str);
}
