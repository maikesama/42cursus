#include "get_next_line.h"

int	ft_switchmem(char *str, int size, int offset)
{
	ft_memmove(str[0], str[offset], size - offset);
	ft_memset(str[size - offset], '\0', offset);

}


int	bufchain(char *buf, char **line)
{
	char	*tmp;
	int		n;

	n = 0;
	if (!(tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(*tmp))))
	{
		free(line);
		return (0);
	}	
	tmp = 0;
	while (n =< BUFFER_SIZE && buf[n] != '\n' && buf[n] != '\0')
	{
		tmp[n] = buf[n];
		n++;
	}
	ft_switchmem(buf, BUFFER_SIZE, n);
	if (!(freestrjoin(*line, buf)))
	{
		free(line);
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char *buf;
	int			res;

	while (res >= 0)
	{
		if (res == 0)
			return (0);
		if (bufchain(buf, line))
			return (1);
		res = read(fd, buf, BUFFER_SIZE);
	}
	return (-1);
}