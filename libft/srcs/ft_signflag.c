/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:02:13 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/01 17:18:04 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_issigned(char *tmp, char flag, char *str)
{
	char	*cpy;

	cpy = NULL;
	if (flag == ' ' && ft_atoi(tmp) >= 0)
		str[0] = ' ';
	if (tmp[0] != '+' && tmp[0] != '-' && flag == '+')
	{
		if (tmp[0] == ' ')
		{
			cpy = ft_strdup(tmp + 1);
			free(tmp);
			tmp = ft_strdup_free(cpy);
		}
		str[0] = '+';
	}
	str[1] = '\0';
	if (str)
		tmp = ft_strjoin_free(str, tmp);
	return (tmp);
}

char		*ft_signflag(char *tmp, char spec, char flag)
{
	char	*str;

	str = NULL;
	if ((spec == 'd' || spec == 'i'))
	{
		if (flag == ' ' || flag == '+')
			str = ft_strnew(ft_strlen(tmp) + 2);
		else
			str = ft_strnew(ft_strlen(tmp) + 1);
		if (!str)
			return (NULL);
		tmp = ft_issigned(tmp, flag, str);
	}
	return (tmp);
}
