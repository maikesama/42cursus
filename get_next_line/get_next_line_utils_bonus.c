/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:51:48 by mpaci             #+#    #+#             */
/*   Updated: 2021/02/16 15:51:51 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char *ptr;

	ptr = b;
	while (n--)
	{
		*ptr++ = c;
	}
	return (b);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	unsigned int	i;
	int				ind;

	i = 0;
	if (!dst && !src && n)
		return (0);
	d = dst;
	s = src;
	while (i < n)
	{
		if (d <= s)
			ind = i;
		else
			ind = n - i - 1;
		*(d + ind) = *(s + ind);
		i++;
	}
	return (dst);
}

int		freestrjoin(char **s1, char *s2)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	n;

	i = 0;
	while (*(*s1 + i))
		i++;
	n = i;
	while (*(s2 + i - n))
		i++;
	if (!(ptr = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	n = 0;
	while (*(*s1 + i))
	{
		ptr[i] = *(*s1 + i);
		i++;
	}
	while (*(s2 + n))
		ptr[i++] = (*(s2 + n++));
	ptr[i] = 0;
	free(*s1);
	*s1 = ptr;
	return (1);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
