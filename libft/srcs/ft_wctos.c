/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 02:25:43 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/11 18:40:08 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_mask(wchar_t value)
{
	char	*str;

	str = NULL;
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = value;
	str[1] = '\0';
	return (str);
}

char		*ft_maskone(unsigned int v, unsigned int mask1)
{
	char	*str;

	str = NULL;
	str = (char *)malloc(sizeof(char) * 3);
	if (!str)
		return (NULL);
	str[0] = (mask1 >> 8) | ((v >> 6) << 27) >> 27;
	str[1] = ((mask1 << 24) >> 24) | (v << 26) >> 26;
	str[2] = '\0';
	return (str);
}

char		*ft_masktwo(unsigned int v, unsigned int mask2)
{
	char	*str;

	str = NULL;
	str = (char *)malloc(sizeof(char) * 4);
	if (!str)
		return (NULL);
	str[0] = (mask2 >> 16) | ((v >> 12) << 28) >> 28;
	str[1] = ((mask2 << 16) >> 24) | ((v >> 6) << 26) >> 26;
	str[2] = ((mask2 << 24) >> 24) | (v << 26) >> 26;
	str[3] = '\0';
	return (str);
}

char		*ft_maskthree(unsigned int v, unsigned int mask3)
{
	char	*str;

	str = NULL;
	str = (char *)malloc(sizeof(char) * 5);
	if (!str)
		return (NULL);
	str[0] = (mask3 >> 24) | ((v >> 18) << 29) >> 29;
	str[1] = ((mask3 << 8) >> 24) | ((v >> 12) << 26) >> 26;
	str[2] = ((mask3 << 16) >> 24) | ((v >> 6) << 26) >> 26;
	str[3] = ((mask3 << 24) >> 24) | (v << 26) >> 26;
	str[4] = '\0';
	return (str);
}

char		*ft_wctos(wchar_t value)
{
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;
	char			*str;
	unsigned int	v;

	v = value;
	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	str = NULL;
	if (ft_sizeb(v) <= 7)
		str = ft_mask(value);
	else if (ft_sizeb(v) <= 11)
		str = ft_maskone(v, mask1);
	else if (ft_sizeb(v) <= 16)
		str = ft_masktwo(v, mask2);
	else
		str = ft_maskthree(v, mask3);
	return (str);
}
