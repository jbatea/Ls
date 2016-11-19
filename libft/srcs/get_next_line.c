/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbateau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:57:01 by jbateau           #+#    #+#             */
/*   Updated: 2016/02/21 17:31:19 by jbateau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_eolchr(char *buf)
{
	int		cnt;

	if ((cnt = ft_strchr_cnt(buf, '\n')) != -1)
		return (ft_strndup(buf, cnt));
	return (NULL);
}

static void			ft_linevalue(char **tmp, char *str)
{
	char	*cpy;

	cpy = NULL;
	if (!tmp)
		*tmp = ft_strdup(str);
	else
	{
		if ((cpy = ft_strdup(*tmp)))
		{
			free(*tmp);
			*tmp = ft_strjoin(cpy, str);
			ft_strdel(&cpy);
		}
	}
}

static int			ft_bufchr(char **buf, char **line)
{
	char		*tmp;

	tmp = NULL;
	if ((*line = ft_eolchr(*buf)) == NULL)
		return (0);
	if ((tmp = ft_strdup(*buf)))
	{
		free(*buf);
		*buf = ft_strndup(tmp + ft_strlen(*line) + 1, BUFF_SIZE);
		ft_strdel(&tmp);
	}
	return (1);
}

static int			ft_read(int const fd, char **buf, char **tmp)
{
	char	*str;
	int		len;
	char	*cpy;

	str = NULL;
	cpy = NULL;
	while ((len = read(fd, *buf, BUFF_SIZE)) > 0 || ft_eolchr(*buf))
	{
		if (len < BUFF_SIZE)
			ft_bzero(*buf + len, BUFF_SIZE - len);
		if ((str = ft_eolchr(*buf)))
		{
			ft_linevalue(tmp, str);
			if ((cpy = ft_strdup(*buf)))
			{
				free(*buf);
				*buf = ft_strndup(cpy + ft_strlen(str) + 1, BUFF_SIZE);
				ft_strdel(&cpy);
			}
			ft_strdel(&str);
			return (1);
		}
		ft_linevalue(tmp, *buf);
	}
	return (len);
}

int					get_next_line(int const fd, char **line)
{
	static char		*buf;
	char			*tmp;
	int				ret;

	tmp = NULL;
	ret = -1;
	if (!line || (!buf && !(buf = ft_strnew(BUFF_SIZE))))
		return (-1);
	else if (ft_bufchr(&buf, line) == 1)
		return (1);
	else if ((tmp = ft_strdup(buf)))
	{
		if ((ret = ft_read(fd, &buf, &tmp)) == 1)
			*line = ft_strdup(tmp);
		if (ret == 0 && *tmp != '\0')
		{
			*line = ft_strdup(tmp);
			*buf = '\0';
			ret = 1;
		}
		ft_strdel(&tmp);
	}
	if (ret != 1)
		ft_strdel(&buf);
	return (ret);
}
