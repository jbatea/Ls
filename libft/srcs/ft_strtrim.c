/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:05:30 by jbateau           #+#    #+#             */
/*   Updated: 2015/12/12 12:05:38 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strtrim(char const *s)
{
	char	*strim;
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (s[i] != '\0')
		while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && (len > 0))
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
