/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharpnfill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 17:44:44 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/27 19:58:41 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_movesharp(char *tmp, char spec)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_strnew(ft_strlen(tmp) + 1);
	if (!str)
		return (NULL);
	str[j] = '0';
	str[j + 1] = spec;
	j = 2;
	while (tmp[i])
	{
		if (tmp[i] == '0' && tmp[i + 1] && tmp[i + 1] == spec)
			i = i + 2;
		str[j] = tmp[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free(tmp);
	tmp = ft_strdup_free(str);
	return (tmp);
}

char		*ft_sharpnfill(char *tmp, char spec)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tmp[i])
	{
		if (tmp[i] == '0' && tmp[i + 1] && tmp[i + 1] == spec)
			j = 1;
		i++;
	}
	if (j == 1)
		tmp = ft_movesharp(tmp, spec);
	if (!tmp)
		return (NULL);
	return (tmp);
}
