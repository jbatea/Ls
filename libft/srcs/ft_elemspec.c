/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elemspec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:00:04 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/29 13:23:57 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_islflag(char *s, char *str, t_lst *lst)
{
	if ((s = ft_lflag(str)))
	{
		ft_newelem(lst, ft_strdup(s));
		str = ft_strdup_free(s);
	}
	else
		ft_newelem(lst, ft_strdup(str));
	return (str);
}

int		*ft_inittab(void)
{
	int *tab;

	tab = (int *)malloc(sizeof(int) * 2);
	if (!tab)
		return (NULL);
	tab[0] = 0;
	tab[1] = 1;
	return (tab);
}

char	*ft_elemspec(char *tmp, va_list pa, t_lst *lst)
{
	char	*str;
	char	*cpy;
	char	*s;
	int		len;
	int		*tab;

	str = NULL;
	cpy = NULL;
	s = NULL;
	tab = ft_inittab();
	str = ft_specret(tmp);
	len = ft_strlen(str);
	if (str && len > 2 && !ft_validflags(str))
		str = ft_islflag(s, str, lst);
	else if (len > 2)
		str = ft_whichflags(str, pa, lst);
	else
		ft_newelem(lst, ft_patype(pa, ft_whichspec(str), tab, lst));
	cpy = ft_strdup(tmp + len);
	free(tmp);
	tmp = ft_strdup_free(cpy);
	ft_strdel(&str);
	free(tab);
	return (tmp);
}
