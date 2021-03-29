/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_%.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:36:11 by mpaci             #+#    #+#             */
/*   Updated: 2021/03/22 16:36:14 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putperc(char c, t_options *options)
{
	int		n;

	sparechar(options);
	write(1, &c, 1);
	options->res += 1;
	if (options->minus && options->width)
	{
		n = options->width - 1;
		while (n--)
		{
			write(1, " ", 1);
			options->res += 1;
		}
		options->minus = 0;
		options->width = 0;
	}
	initialize_struct(options);
}
