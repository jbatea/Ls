/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 20:19:17 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/29 19:17:05 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int			ft_countl(long int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char				*ft_ltoa(long int n)
{
	char	*str;
	int		len;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	len = ft_countl(n);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	str[len + 1] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	if (n < 10)
		str[len] = n + '0';
	return (str);
}
