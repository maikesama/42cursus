/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:05:17 by mpaci             #+#    #+#             */
/*   Updated: 2021/01/26 16:05:19 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_start(char *s1, char *set)
{
	while (ft_srcchar_bonus(set, *s1))
	{
		s1++;
	}
	return (s1);
}

char	*ft_end(char *s1, char *set)
{
	while (ft_srcchar_bonus(set, *s1))
	{
		s1--;
	}
	return (s1 + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	char	*start;
	char	*end;
	int		size;

	if (!(s1) || !(set))
		return (0);
	start = ft_start((char *)s1, (char *)set);
	end = ft_end((char *)&s1[ft_strlen(s1) - 1], (char *)set);
	size = end - start;
	if (start >= &s1[ft_strlen(s1)])
	{
		if (!(ptr = ft_calloc(1, sizeof(*ptr))))
			return (0);
		return (ptr);
	}
	if (!(ptr = ft_calloc(size, sizeof(*ptr))))
		return (0);
	ft_memcpy(ptr, start, size);
	return (ptr);
}
