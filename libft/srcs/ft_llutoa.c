/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 19:03:32 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/30 19:07:14 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_countllu(unsigned long long int n)
{
	int		i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char				*ft_llutoa(unsigned long long int n)
{
	char	*str;
	int		len;

	len = ft_countllu(n);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (str == NULL)
		return (NULL);
	str[len + 1] = '\0';
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
