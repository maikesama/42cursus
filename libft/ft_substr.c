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
	char *ptr;

	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
	{
		if (!(ptr = ft_calloc(1, sizeof(*ptr))))
			return (0);
		return (ptr);
	}
	if (!(ptr = ft_calloc(ft_min_bonus(len, ft_strlen(s)) + 1, sizeof(*ptr))))
		return (0);
	ft_strlcpy(ptr, &s[start], len + 1);
	return (ptr);
}
