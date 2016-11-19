/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:48:35 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/29 15:32:40 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	int		cnt;
	va_list pa;
	t_lst	*lst;

	lst = ft_listinit();
	if (format && lst)
	{
		va_start(pa, format);
		cnt = ft_checkformat(format, lst);
		if (cnt == 1)
			ft_printarg(format, pa, lst);
		ft_printlist(lst);
		if (cnt != -1)
			cnt = ft_lststrlen(lst);
		ft_lstfree(&lst);
		va_end(pa);
	}
	else
		cnt = -1;
	return (cnt);
}
