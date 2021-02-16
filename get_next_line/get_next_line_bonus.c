/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:51:28 by mpaci             #+#    #+#             */
/*   Updated: 2021/02/16 15:51:30 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	clean(char **buf)
{
	int i;

	i = 0;
	while (i < OPEN_MAX)
	{
		if (buf[i] && buf[i][0] == 0)
		{
			free(buf[i]);
			buf[i] = 0;
		}
		i++;
	}
	return (1);
}

int	initialize_buf(char **buf, int fd)
{
	if (!buf[fd])
	{
		if (!(buf[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		{
			clean(buf);
			return (0);
		}
		ft_memset(buf[fd], 0, BUFFER_SIZE + 1);
	}
	return (1);
}

int	ft_switchmem(char *str, int size, int offset)
{
	ft_memmove(&str[0], &str[offset], size - offset);
	ft_memset(&str[size - offset], 0, offset);
	return (1);
}

int	bufchain(char **buf, int fd, char **line)
{
	char	*tmp;
	int		n;
	char	*slot;

	slot = buf[fd];
	if (!(tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	*tmp = 0;
	n = 0;
	while (n < BUFFER_SIZE && slot[n] != 0 && slot[n] != '\n')
	{
		*(tmp + n) = slot[n];
		n++;
	}
	*(tmp + n) = 0;
	ft_switchmem(slot, BUFFER_SIZE, n);
	if (!(freestrjoin(line, tmp)))
	{
		free(tmp);
		clean(buf);
		return (0);
	}
	free(tmp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char *buf[OPEN_MAX];
	int			res;

	if (fd < 0 || BUFFER_SIZE <= 0 || (fd > OPEN_MAX && clean(buf)))
		return (-1);
	if (!initialize_buf(buf, fd))
		return (-1);
	if (!(*line = malloc(sizeof(char))) && clean(buf))
		return (-1);
	**line = 0;
	res = 1;
	while (res >= 0)
	{
		if (!(bufchain(buf, fd, line)))
			return (-1);
		if (buf[fd][0] == '\n' && ft_switchmem(buf[fd], BUFFER_SIZE, 1))
			return (1);
		if (res == 0)
			return (0);
		res = read(fd, buf[fd], BUFFER_SIZE);
	}
	clean(buf);
	return (-1);
}
