/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_cnt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:45:31 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/31 14:47:46 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			ft_strrchr_cnt(char *s, char c)
{
	int		cnt;

	cnt = ft_strlen(s);
	while (cnt > 0 && s[cnt] != c)
		cnt--;
	if (s[cnt] == c)
		return (cnt);
	return (-1);
}
