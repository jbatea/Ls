/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:13:02 by jbateau           #+#    #+#             */
/*   Updated: 2016/03/16 14:13:25 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_checkflags(const char *format)
{
	char	*tmp;
	char	*spec;

	spec = NULL;
	tmp = ft_strdup((char *)format);
	while (ft_strlen(tmp) > 0)
	{
		spec = ft_specret(tmp);
		if (!spec)
			return (1);
		if (!ft_validflags(spec))
			return (0);
		tmp = ft_strdup(tmp + ft_strlen(spec));
	}
	return (1);
}
