/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specret.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:37:43 by jbateau           #+#    #+#             */
/*   Updated: 2016/02/26 18:38:24 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_specret(const char *format)
{
	int		cnt;
	int		i;

	i = 0;
	if ((cnt = ft_strchr_cnt((char *)format, '%')) != -1)
	{
		i = cnt + 1;
		while (format[i])
		{
			if (ft_isspecifier(format[i]) == 1)
				return (ft_strndup(format + cnt, i + 1 - cnt));
			i++;
		}
	}
	return (NULL);
}
