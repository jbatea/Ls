/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 16:39:21 by jbateau           #+#    #+#             */
/*   Updated: 2016/02/21 17:25:56 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_counthexa(int n)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (n < 0)
	{
		j = 1;
		n = -n;
	}
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	if (i < 8 && j == 1)
		i = 7;
	return (i);
}

static char		*ft_inegtox(int n)
{
	int			i;
	char		*str;
	char		*tmp;

	i = 0;
	str = ft_itox(-n);
	if (!(tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		if (str[i] > 53 && str[i] < 58)
			tmp[i] = 63 - str[i] + '0';
		else
			tmp[i] = 70 - str[i] + '0';
		i++;
	}
	tmp[i] = '\0';
	free(str);
	str = ft_itox(ft_xtoi(tmp) + 1);
	free(tmp);
	while (ft_strlen(str) < 8)
		str = ft_strjoin_free(ft_strdup("F"), str);
	return (str);
}

char			*ft_itox(int n)
{
	char	*str;
	int		i;

	i = ft_counthexa(n);
	if (n < 0)
		return (ft_inegtox(n));
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
