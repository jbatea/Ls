/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:41:48 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/14 20:59:42 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_ifisstr(char *tmp, char *str, char *cpy, t_lst *lst)
{
	ft_newelem(lst, ft_strdup(str));
	cpy = ft_strdup(tmp + ft_strlen(str));
	free(tmp);
	tmp = ft_strdup_free(cpy);
	ft_strdel(&str);
	return (tmp);
}

void				ft_printarg(const char *format, va_list pa, t_lst *lst)
{
	int				i;
	char			*str;
	char			*tmp;
	char			*cpy;

	i = 0;
	tmp = ft_strdup((char *)format);
	str = NULL;
	cpy = NULL;
	while (i < ft_speccnt(format))
	{
		if ((str = ft_isstr(tmp)))
			tmp = ft_ifisstr(tmp, str, cpy, lst);
		else
		{
			tmp = ft_elemspec(tmp, pa, lst);
			i++;
		}
	}
	if (tmp)
		ft_newelem(lst, ft_strdup(tmp));
	ft_strdel(&tmp);
}
