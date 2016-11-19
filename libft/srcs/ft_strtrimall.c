/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 11:15:50 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/27 19:56:52 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_istrim(char c)
{
	if (c == '\n' || c == ' ' || c == '\t' || c == '\v' || c == '\r'
			|| c == '\f')
		return (1);
	return (0);
}

char		*ft_strtrimall(char const *s)
{
	char	*strim;
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	strim = NULL;
	len = ft_strlen(s) - 1;
	while (s[i] && ft_istrim(s[i]))
		i++;
	if (s[i] != '\0')
		while ((len > 0) && ft_istrim(s[len]))
			len--;
	if (!(strim = (char *)malloc(sizeof(char) * ((len - i) + 2))))
		return (NULL);
	while (i < (len + 1) && s[i])
	{
		strim[j] = s[i];
		i++;
		j++;
	}
	strim[j] = '\0';
	return (strim);
}
