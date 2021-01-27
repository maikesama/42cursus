/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:33:40 by mpaci             #+#    #+#             */
/*   Updated: 2021/01/25 13:33:44 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	i = 0;
	if (!(s))
		return (0);
	ptr = malloc(sizeof(char) * (len + 1));
	if ((int)start >= ft_strlen(s))
		return (ptr);
	if (!(ptr = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ptr[j] = s[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}
