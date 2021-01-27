/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:33:54 by mpaci             #+#    #+#             */
/*   Updated: 2021/01/25 13:33:57 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	if (!(s1) || !(s2))
		return (0);
	if (!(ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	ft_memmove(ptr, s1, ft_strlen(s1));
	ft_memmove(&ptr[ft_strlen(s1)], s2, ft_strlen(s2));
	ptr[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (ptr);
}
