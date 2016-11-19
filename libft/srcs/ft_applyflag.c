/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:03:10 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/01 17:50:08 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_float(int *tab, char s, char *tmp)
{
	char	*cpy;

	cpy = NULL;
	if (tab[0] > 0 && s == 's')
	{
		cpy = ft_strdup_free(tmp);
		tmp = ft_strndup(cpy, tab[0]);
		ft_strdel(&cpy);
	}
	if (tab[0] > 0 && (s == 'g' || s == 'G'))
	{
		if (ft_atoi(tmp) < 0)
			tab[0]++;
		cpy = ft_strdup_free(tmp);
		tmp = ft_strndup(cpy, tab[0]);
		tmp = ft_strjoin_free(tmp, ft_strndup(cpy + tab[0] + 1, 1));
		ft_strdel(&cpy);
	}
	if (tab[0] > 0 && (s == 'f' || s == 'F'))
		tmp = ft_doubleprec(tmp, tab[0]);
	if (tab[0] > 0 && (s == 'e' || s == 'E'))
		tmp = ft_dprecsci(tmp, tab[0]);
	return (tmp);
}

char		*ft_firstflag(char *tmp, int *tab, char s, char f)
{
	if (ft_atoi(tmp) == 0 && tab[0] == -1 && s != '%')
	{
		ft_strdel(&tmp);
		tmp = ft_strdup("");
	}
	if (f == '#' && (s == 'o' || s == 'O') && tab[0] == -1)
	{
		if (ft_atoi(tmp) == 0)
		{
			free(tmp);
			tmp = ft_strdup("0");
		}
		tab[0] = -2;
	}
	return (tmp);
}

void		ft_spaceandzero(char f, int *tab)
{
	if (f == ' ')
		tab[4] = 1;
	if (f == '0')
		tab[5] = 1;
}

char		*ft_applyflag(char *tmp, char f, char s, int *tab)
{
	ft_spaceandzero(f, tab);
	if (tab[0] == -1 && (s == 's' || s == 'c' || s == 'S'))
		return (ft_strdup(""));
	tmp = ft_firstflag(tmp, tab, s, f);
	tmp = ft_applysharp(s, tmp, f);
	if (f == '+' || f == ' ')
		tmp = ft_signflag(tmp, s, f);
	if (tab[0] > 0 && f == '0' && (s == 'd' || s == 'i'))
		tmp = ft_fillflag(tmp, tab[0]);
	if (!tab[0] && f == '0' && tab[1] > 0 && s != 's' && s != 'c')
	{
		tmp = ft_fillflag(tmp, tab[1]);
		if (s == 'x' || s == 'X')
			tmp = ft_sharpnfill(tmp, s);
	}
	tmp = ft_lenandzero(s, tmp, tab, f);
	tmp = ft_float(tab, s, tmp);
	if (tab[4] && tab[5])
		tmp = ft_flagorder(tmp, 'c');
	return (tmp);
}
