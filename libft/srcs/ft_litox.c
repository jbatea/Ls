/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litox.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 19:09:44 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/23 18:21:30 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_counthexa(unsigned long n)
{
	int			i;

	i = 0;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char			*ft_litox(unsigned long n)
{
	char	*str;
	int		i;

	i = ft_counthexa(n);
	if (!(str = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	str[i + 1] = '\0';
	while (n >= 16)
	{
		if ((n % 16) < 10)
			str[i] = n % 16 + 48;
		else
			str[i] = n % 16 + 55;
		n = n / 16;
		i--;
	}
	if (n < 10)
		str[i] = n + 48;
	else if (n < 16)
		str[i] = n + 55;
	return (str);
}
