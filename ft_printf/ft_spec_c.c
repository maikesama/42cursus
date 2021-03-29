/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:38:18 by mpaci             #+#    #+#             */
/*   Updated: 2021/03/22 16:38:21 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sparechar(t_options *options)
{
	int	n;

	if (!options->minus && options->width)
	{
		n = options->width - 1;
		while (n--)
		{
			write(1, (!options->zero ? " " : "0"), 1);
			options->res += 1;
		}
		options->width = 0;
	}
}

void	ft_putchar_args(va_list args, t_options *options)
{
	char	c;
	int		n;

	c = va_arg(args, int);
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
	}
	initialize_struct(options);
}
