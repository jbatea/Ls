/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagpriority.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:57:41 by jbateau           #+#    #+#             */
/*   Updated: 2016/04/26 15:44:43 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*ft_priority(char *str)
{
	int		i;
	char	*tmp;
	char	*cpy;

	i = ft_strchr_cnt(str, '0');
	tmp = ft_strndup(str, i);
	cpy = ft_strdup(str + i + 1);
	free(str);
	str = ft_strjoin_free(tmp, cpy);
	return (str);
}

char		*ft_bpriority(char *str)
{
	int		i;
	char	*tmp;
	char	*cpy;

	i = ft_strchr_cnt(str, ' ');
	tmp = ft_strndup(str, i);
	cpy = ft_strdup(str + i + 1);
	free(str);
	str = ft_strjoin_free(tmp, cpy);
	return (str);
}

int			*ft_initflag(void)
{
	int		i;
	int		*flag;

	i = 0;
	flag = (int *)malloc(sizeof(int) * 4);
	if (!flag)
		return (NULL);
	while (i < 4)
	{
		flag[i] = 0;
		i++;
	}
	return (flag);
}

char		*ft_wflags(int *flag, char *str)
{
	if (flag[1] && flag[2])
		str = ft_flagorder(str, ' ');
	if (flag[1] && flag[3])
		str = ft_flagorder(str, '+');
	if (flag[0] && flag[1])
		str = ft_priority(str);
	if (flag[2] && flag[3])
		str = ft_bpriority(str);
	free(flag);
	return (str);
}

char		*ft_flagpriority(char *str)
{
	int		i;
	int		j;
	int		*flag;

	i = 0;
	j = 0;
	flag = ft_initflag();
	while (str[i])
	{
		if (ft_isdigit(str[i]) && str[i] != '0')
			j = 1;
		if (str[i] == '-' && j == 0)
			flag[0] = 1;
		if (str[i] == '0' && j == 0)
			flag[1] = 1;
		if (str[i] == ' ' && j == 0)
			flag[2] = 1;
		if (str[i] == '+' && j == 0)
			flag[3] = 1;
		i++;
	}
	return (ft_wflags(flag, str));
}
