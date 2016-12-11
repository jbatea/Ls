/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 17:26:04 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/23 18:05:31 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_lltob(unsigned long n)
{
	char	*str;
	int		i;

	i = ft_sizeb(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i + 1] = '\0';
	while (n >= 2)
	{
		str[i] = n % 2 + 48;
		n = n / 2;
		i--;
	}
	if (n < 2)
		str[i] = n + 48;
	if (i > 0)
	{
		i--;
		str[i] = '-';
	}
	return (str);
}
