/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:42:04 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/31 14:42:34 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strscmp(char *str, char *cmp1, char *cmp2)
{
	if (!ft_strcmp(str, cmp1) || !ft_strcmp(str, cmp2))
		return (0);
	return (1);
}
