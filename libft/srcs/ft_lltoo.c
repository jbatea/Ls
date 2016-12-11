/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:25:19 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/25 14:59:47 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_sizeoct(unsigned long long n)
{
	int		i;

	i = 0;
	while (n >= 8)
	{
		n = n / 8;
		i++;
	}
	return (i);
}

char		*ft_lltoo(unsigned long long n)
{
	char	*str;
	int		len;

	len = ft_sizeoct(n);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	str[len + 1] = '\0';
	while (n >= 8)
	{
		str[len] = n % 8 + '0';
		n = n / 8;
		len--;
	}
	if (n < 8)
		str[len] = n + '0';
	return (str);
}
