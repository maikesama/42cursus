/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_fuktu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:10:28 by mpaci             #+#    #+#             */
/*   Updated: 2021/03/22 17:10:30 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	sparxtu(char *s, t_options *options, int n)
{
	if (options->precision > options->width)
		n = options->precision - ft_strlen(s);
	else if (options->precision > ft_strlen(s) &&
			options->precision < options->width)
		n = options->width - options->precision;
	else if (s[0] == '0' && !options->precision)
		n = options->width;
	else
		n = options->width - ft_strlen(s);
	while (n--)
	{
		write(1, options->precision >= options->width ? "0" : " ", 1);
		options->res += 1;
	}
	if (options->precision < options->width &&
		options->precision > ft_strlen(s))
	{
		n = (options->precision) - ft_strlen(s);
		while ((n--) && options->res++)
			ft_putchar('0');
	}
}

void	min_zero(const char *str, t_options *options)
{
	if (str[options->it] == '-')
		options->minus = 1;
	else
		options->zero = 1;
}
