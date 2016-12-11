/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubleprec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 16:48:42 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/06 17:53:53 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_fill(char *str, int l)
{
	while (l < 6)
	{
		if (!str)
			str = ft_strjoin(str, "0");
		l++;
	}
	return (str);
}

int			ft_lendec(char *tmp)
{
	int			i;

	i = 0;
	while (tmp[i] && tmp[i] != '.')
		i++;
	return ((int)ft_strlen(tmp) - i);
}

char		*ft_ispreclarger(int prec, char *tmp, int i)
{
	char	*str;
	int		len;
	int		l;

	str = NULL;
	len = ft_strlen(tmp);
	l = ft_lendec(tmp) + 1;
	if (prec)
	{
		while ((len - i) < prec)
		{
			if (!str)
				str = ft_strjoin_free(tmp, ft_strdup("0"));
			else
				str = ft_strjoin_free(str, ft_strdup("0"));
			prec--;
		}
		if (str)
			str = ft_strjoin_free(str, ft_strdup("0"));
	}
	str = ft_fill(str, l);
	return (str);
}

char		*ft_doubleprec(char *tmp, int prec)
{
	int		i;
	int		len;
	char	*str;
	char	*cpy;

	i = 0;
	len = ft_strlen(tmp);
	str = NULL;
	cpy = NULL;
	while (tmp[i] && tmp[i] != '.')
		i++;
	if ((len - i) > prec)
	{
		cpy = ft_strdup_free(tmp);
		str = ft_strndup(cpy, i + prec);
		str = ft_strjoin_free(str, ft_strndup(cpy + i + prec + 1, 1));
		ft_strdel(&cpy);
	}
	else
		str = ft_ispreclarger(prec, tmp, i);
	if (str)
		tmp = ft_strdup_free(str);
	return (tmp);
}
