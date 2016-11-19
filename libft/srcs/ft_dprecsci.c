/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprecsci.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 16:47:32 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/20 16:48:38 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dscilen(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] && (tmp[i] != 'E' && tmp[i] != 'e'))
		i++;
	return (i);
}

char	*ft_dprecsci(char *tmp, int prec)
{
	int		i;
	int		len;
	char	*str;
	char	*cpy;

	i = 0;
	len = ft_dscilen(tmp);
	str = NULL;
	cpy = NULL;
	while (tmp[i] && tmp[i] != '.')
		i++;
	if ((len - i) > prec)
	{
		str = ft_strndup(tmp, i + prec);
		if ((i + prec + 1) < len)
			str = ft_strjoin_free(str, ft_strndup(tmp + i + prec + 1, 1));
		else if ((i + prec + 1) == len)
			str = ft_strjoin_free(str, ft_strndup(tmp + i + prec, 1));
		cpy = ft_strdup(tmp + len);
		free(tmp);
		tmp = ft_strjoin_free(str, cpy);
	}
	return (tmp);
}
