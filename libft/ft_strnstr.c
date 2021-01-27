/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:02:50 by mpaci             #+#    #+#             */
/*   Updated: 2021/01/18 17:02:52 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	char	*ptr2;
	char	*ptr1;

	ptr1 = (char *)big;
	if ((little[0] == 0 && big[0] == 0) || little[0] == 0)
		return ((char *)big);
	if (ft_strlen(little) > ft_strlen(big))
		return (0);
	while (n && *ptr1 != 0)
	{
		ptr2 = (char *)little;
		while (*ptr1 == *ptr2 && *ptr1 && n)
		{
			ptr1++;
			ptr2++;
			n--;
		}
		if (*ptr2 == 0)
			return (ptr1 - ft_strlen((char *)little));
		ptr1++;
		n--;
	}
	return (0);
}
