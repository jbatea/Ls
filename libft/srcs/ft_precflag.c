/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:07:13 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/31 14:50:02 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_precflag(char *str)
{
	char	*tmp;
	char	*cpy;
	int		i;
	int		j;

	i = ft_strchr_cnt(str, '.');
	j = i + 1;
	while (str[j] && (str[j] == '+' || ft_isdigit(str[j])))
		j++;
	tmp = ft_strndup(str, i + 1);
	cpy = ft_strndup(str + i + 1, ft_strlen(str) - j + 1);
	free(str);
	str = ft_strjoin_free(tmp, cpy);
	return (str);
}
