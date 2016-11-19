/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 18:47:37 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/29 15:49:36 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_checkformat(const char *format, t_lst *lst)
{
	char	*tmp;
	int		cnt;
	int		i;

	i = 1;
	tmp = ft_strdup((char *)format);
	cnt = ft_speccnt(tmp);
	if (tmp && cnt == -1)
	{
		if (ft_eolspec(tmp))
			i = -1;
	}
	if (tmp && (cnt == 0 || cnt == -1) && i == -1)
	{
		if (cnt == -1 && ft_lflag(tmp))
			tmp = ft_lflag(tmp);
		if (cnt == -1)
			tmp = ft_normtmp(tmp);
		ft_newelem(lst, ft_strdup(tmp));
	}
	ft_strdel(&tmp);
	return (i);
}
