/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:50:07 by jbateau           #+#    #+#             */
/*   Updated: 2017/05/31 14:53:58 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		my_newelem(t_lst *lst, char *str, int i)
{
	t_lst		*new;
	t_lst		*cur;

	cur = lst;
	new = (t_lst *)malloc(sizeof(t_lst));
	ft_bzero(new, sizeof(t_lst));
	if (new)
	{
		new->cpy = ft_strndup(str, i);
		new->next = NULL;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}

static char		*my_space_display(long int n)
{
	char		*str;

	str = NULL;
	str = ft_strnew(n);
	(str) ? ft_memset((void *)str, ' ', n) : 0;
	return (str);
}

static char		*my_pa(va_list pa, char c)
{
	char		*s;

	if (c == 's')
		return (ft_strdup(va_arg(pa, char *)));
	if (c == '*')
		return (my_space_display(va_arg(pa, long int)));
	if (c == 'c')
	{
		s = ft_strnew(sizeof(char));
		s[0] = (char)va_arg(pa, int);
		return (s);
	}
	return (ft_ltoa(va_arg(pa, long int)));
}

static void		ft_add_arg(char *format, va_list pa, t_lst *lst)
{
	int			i;
	char		*str;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	(i) ? my_newelem(lst, format, i) : 0;
	if (format[i] && format[i] == '%')
	{
		i++;
		while (format[i] == '*')
		{
			if ((str = my_pa(pa, format[i])))
			{
				my_newelem(lst, str, ft_strlen(str));
				ft_strdel(&str);
			}
			i++;
		}
		str = my_pa(pa, format[i]);
		my_newelem(lst, str, ft_strlen(str));
		ft_strdel(&str);
		i++;
	}
	(format[i]) ? ft_add_arg(format + i, pa, lst) : 0;
}

int				ft_fprintf(int fd, const char *format, ...)
{
	va_list		pa;
	int			ret;
	t_lst		*lst;

	ret = -1;
	lst = ft_listinit();
	if (format && lst)
	{
		va_start(pa, format);
		ft_add_arg((char *)format, pa, lst);
		ft_printlist(lst, fd);
		ft_lstfree(&lst);
		va_end(pa);
	}
	return (ret);
}
