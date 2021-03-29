/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_fuk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:27:22 by mpaci             #+#    #+#             */
/*   Updated: 2021/03/22 16:27:24 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_struct_two(t_options *options)
{
	options->res = 0;
	options->it = 0;
}

void	fukkino(t_options *options)
{
	options->it++;
	options->res += 1;
}

void	search_all(const char *str, va_list ap, t_options *options)
{
	search_flag_one(str, ap, options);
	search_flag_two(str, ap, options);
	if (!search_char_one(str, ap, options))
		search_char_two(str, ap, options);
}

void	sparring(char *s, t_options *options, int n)
{
	n = options->width - (options->precision != -1 ?
			min(ft_strlen(s), options) : ft_strlen(s));
	while (n--)
	{
		write(1, " ", 1);
		options->res += 1;
	}
}

void	sparx(char *s, t_options *options, int n)
{
	n = options->width - options->precision;
	while (n-- && options->res++)
		write(1, " ", 1);
	n = options->precision - ft_strlen(s);
	while (n-- && options->res++)
		write(1, "0", 1);
}
