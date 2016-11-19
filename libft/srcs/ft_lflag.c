/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lflag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:44:23 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/27 20:47:16 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_ldup(char *tmp, int i, int j, char *str)
{
	char	*cpy;

	cpy = NULL;
	cpy = ft_strndup(tmp, i + 1 + j);
	free(tmp);
	tmp = ft_strjoin(cpy, str + j + 1);
	ft_strdel(&str);
	ft_strdel(&cpy);
	return (tmp);
}

char		*ft_lflag(char *tmp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	while (tmp[i] && tmp[i] != '%')
		i++;
	if (tmp[i] == '%')
		str = ft_strdup(tmp + i);
	while (str[j])
	{
		if (str[j] == 'l' || str[j] == 'z' || str[j] == 'h' || str[j] == 'j')
		{
			if ((str[j] == 'h' && str[j + 1] && str[j + 1] == 'h') ||
					(str[j] == 'l' && str[j + 1] && str[j + 1] == 'l'))
				j++;
			return (ft_ldup(tmp, i, j, str));
		}
		j++;
	}
	if (str)
		ft_strdel(&str);
	return (NULL);
}
