/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:07:13 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/16 14:07:35 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_precflag(char *str)
{
	char	*tmp;
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '.')
		i++;
	j = i + 1;
	while (str[j] && (str[j] == '+' || ft_isdigit(str[j])))
		j++;
	tmp = ft_strndup(str, i);
	cpy = ft_strdup(str + j);
	free(str);
	str = ft_strjoin_free(tmp, cpy);
	return (str);
}
