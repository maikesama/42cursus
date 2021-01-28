/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_driver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:54:17 by mpaci             #+#    #+#             */
/*   Updated: 2021/01/14 17:54:20 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	//char string[] = "      split       this for   me  !       ";
	//ft_strnstr(s1, s2, n);
	//strnstr(s1, s1, max);
	//printf("emulation %s\n vs\noriginal %s\n", ft_strnstr(s1, s1, max), strnstr(s1, s1, max));
	//printf("%s\n", itoa(s1));
	/*char **out = ft_split("      split       this for   me  !       ", ' ');
	int i = 0;
	while (out[i])
	{
		printf("%s\n", out[i]);
		//free (out[i]);
		i++;
	}
	free (out);*/
	ft_split("      split       this for   me  !       ", ' ');
	//char *out = ft_strtrim(s1, set);
	//free (out);
	return 0;
}
