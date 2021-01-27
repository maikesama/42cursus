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
	char s1[100] = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
	char set[7] = " \n\t";
	//ft_strnstr(s1, s2, n);
	//strnstr(s1, s1, max);
	//printf("emulation %s\n vs\noriginal %s\n", ft_strnstr(s1, s1, max), strnstr(s1, s1, max));
	//printf("%s\n", itoa(s1));
	printf("%s\n", ft_strtrim(s1, set));
	return 0;
}
