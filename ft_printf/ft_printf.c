/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:20:44 by mpaci             #+#    #+#             */
/*   Updated: 2021/03/22 16:20:47 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wid_conversion(const char *str, int start, t_options *options)
{
	options->width = ft_atoi_flag(str, start);
}

void	prec_conversion(const char *str, int start, t_options *options)
{
	options->precision = ft_atoi_flag(str, start);
}

int		ft_printf(const char *str, ...)
{
	t_options	*options;
	t_options	opt;
	va_list		ap;

	options = &opt;
	va_start(ap, str);
	initialize_struct(options);
	initialize_struct_two(options);
	while (str[options->it])
	{
		if (str[options->it] != '%')
		{
			write(1, &str[options->it], 1);
			fukkino(options);
		}
		else
		{
			options->it++;
			search_all(str, ap, options);
		}
	}
	va_end(ap);
	return (options->res);
}
