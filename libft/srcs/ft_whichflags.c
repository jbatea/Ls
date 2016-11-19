/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whichflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:08:53 by jbateau           #+#    #+#             */
/*   Updated: 2016/05/01 17:56:49 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_checkleft(int *tab, char *str, char *tmp)
{
	if (tab[2] == 0 && tab[1] > 0)
	{
		if (str[ft_strlen(str) - 1] == 'c' && tmp[0] == '\0')
			tab[1]--;
		tmp = ft_rightalig(tmp, tab[1]);
	}
	if (tab[2] == 1)
		tmp = ft_leftalig(tmp, tab[1]);
	return (tmp);
}

char		*ft_apply(char *str, char *tmp, int *tab)
{
	int		j;

	j = 0;
	while (str[j] && (j < (int)(ft_strlen(str) - 1)))
	{
		if (tab[1] && str[j] == '0' && str[j + 1] && str[j + 1] == '+'
				&& tmp[0] != '-')
			tab[1]--;
		tmp = ft_applyflag(tmp, str[j], str[ft_strlen(str) - 1], tab);
		j++;
	}
	return (tmp);
}

int			*ft_inittab1(void)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 7);
	if (tab)
	{
		tab[0] = 0;
		tab[1] = 0;
		tab[2] = 0;
		tab[3] = 0;
		tab[4] = 0;
		tab[5] = 0;
		tab[6] = 0;
	}
	return (tab);
}

int			*ft_inittab2(void)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 2);
	if (tab)
	{
		tab[0] = 0;
		tab[1] = 0;
		tab[2] = 0;
	}
	return (tab);
}

char		*ft_whichflags(char *str, va_list pa, t_lst *lst)
{
	int		*tab;
	int		*tab2;
	char	*tmp;

	tab = ft_inittab1();
	tab2 = ft_inittab2();
	tmp = NULL;
	if ((tab2[0] = ft_lenmod(str)))
		str = ft_lflag(str);
	tab2[2] = ft_lenchr(str);
	if ((tmp = ft_patype(pa, str[ft_strlen(str) - 1], tab2, lst)))
	{
		str = ft_flagpriority(str);
		tab[2] = ft_leftflagchr(str);
		str = ft_lenandprec(str, tab);
		if (tab2[2] == 0)
			tab[1] = 0;
		tmp = ft_apply(str, tmp, tab);
		tmp = ft_checkleft(tab, str, tmp);
		ft_newelem(lst, ft_strdup(tmp));
		tab[6] = 0;
	}
	ft_freeall(tab, tab2, tmp);
	return (str);
}
