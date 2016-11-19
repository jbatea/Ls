/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:44:21 by jbateau           #+#    #+#             */
/*   Updated: 2015/12/07 17:29:39 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;
	int		count;
	int		len;

	count = 0;
	i = ft_countstring(s, c);
	j = 0;
	tab = (char **)malloc(sizeof(char *) * (i + 1));
	if (tab == NULL)
		return (NULL);
	while (j < i)
	{
		len = ft_sizestring(s, c, &count);
		tab[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (tab[j] == NULL)
			return (NULL);
		tab[j] = ft_strncpy(tab[j], s + (count - len), len);
		tab[j][len] = '\0';
		j++;
	}
	tab[i] = NULL;
	return (tab);
}
