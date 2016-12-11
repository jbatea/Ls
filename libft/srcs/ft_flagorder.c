/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:16:03 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/26 16:24:36 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_ordersigned(char *str)
{
	int		i;
	char	*tmp;
	char	*cpy;

	i = ft_strchr_cnt(str, '0');
	tmp = ft_strndup(str, i);
	cpy = ft_strdup(str + i + 1);
	free(str);
	str = ft_strjoin_free(tmp, cpy);
	tmp = ft_strdup(str + 1);
	free(str);
	str = ft_strjoin_free(ft_strdup("0"), tmp);
	str = ft_strjoin_free(ft_strdup("%"), str);
	return (str);
}

char	*ft_orderspace(char *str)
{
	int		i;
	char	*tmp;
	char	*cpy;

	i = ft_strchr_cnt(str, ' ');
	tmp = ft_strndup(str, i);
	cpy = ft_strdup(str + i + 1);
	free(str);
	str = ft_strjoin_free(tmp, cpy);
	str = ft_strjoin_free(ft_strdup(" "), str);
	str = ft_strjoin_free(ft_strdup("%"), str);
	return (str);
}

char	*ft_finalorder(char *str)
{
	int		i;
	char	*tmp;
	char	*cpy;

	i = ft_strchr_cnt(str, ' ');
	if (i)
	{
		tmp = ft_strndup(str, i);
		cpy = ft_strdup(str + i + 1);
		free(str);
		str = ft_strjoin_free(tmp, cpy);
	}
	return (str);
}

char	*ft_flagorder(char *str, char c)
{
	if (c == '+')
		str = ft_ordersigned(str);
	if (c == ' ')
		str = ft_orderspace(str);
	if (c == 'c')
		str = ft_finalorder(str);
	return (str);
}
