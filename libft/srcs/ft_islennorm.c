/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islennorm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 14:53:48 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/30 17:52:19 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_islennorm(char *str)
{
	char	*tmp;
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && (str[i] != '-' || (str[i + 1] && !ft_isdigit(str[i + 1])))
			&& !ft_isdigit(str[i]))
		i++;
	if (str[i] == '0')
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '#')
		i++;
	j = i + 1;
	while (str[j] && (ft_isdigit(str[j])))
		j++;
	tmp = ft_strndup(str, i);
	cpy = ft_strdup(str + j);
	free(str);
	str = ft_strjoin_free(tmp, cpy);
	return (str);
}
