/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:37:54 by mpaci             #+#    #+#             */
/*   Updated: 2021/03/22 18:37:56 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	search_flag_one(const char *str, va_list ap, t_options *options)
{
	if (str[options->it] == '-' || str[options->it] == '0')
	{
		min_zero(str, options);
		options->it++;
	}
	if (str[options->it] == '0' || str[options->it] == '-')
	{
		min_zero(str, options);
		if (options->minus == 1)
			options->zero = 0;
		options->it++;
	}
	if (str[options->it] == '*')
	{
		options->width = va_arg(ap, int);
		if (options->width < 0)
		{
			options->minus = 1;
			options->zero = 0;
			options->width *= -1;
		}
		options->it++;
	}
}

void	search_flag_two(const char *str, va_list ap, t_options *options)
{
	if (str[options->it] >= '1' && str[options->it] <= '9')
	{
		wid_conversion(str, options->it, options);
		while (str[options->it] >= '0' && str[options->it] <= '9')
			options->it++;
	}
	if (str[options->it] == '.')
	{
		options->it++;
		if (str[options->it] == '*')
		{
			options->precision = va_arg(ap, int);
			options->it++;
		}
		else if (str[options->it] >= '0' && str[options->it] <= '9')
			prec_conversion(str, options->it, options);
		else
			options->precision = 0;
		while (str[options->it] >= '0' && str[options->it] <= '9')
			options->it++;
	}
}

int		search_char_one(const char *str, va_list ap, t_options *options)
{
	if (str[options->it] == '%')
	{
		ft_putperc('%', options);
		options->it++;
		return (1);
	}
	else if (str[options->it] == 'c')
	{
		ft_putchar_args(ap, options);
		options->it++;
		return (1);
	}
	else if (str[options->it] == 's')
	{
		ft_putstr_args(ap, options);
		options->it++;
		return (1);
	}
	else if (str[options->it] == 'd' || str[options->it] == 'i')
	{
		ft_putnbr_args(ap, options);
		options->it++;
		return (1);
	}
	return (0);
}

void	search_char_two(const char *str, va_list ap, t_options *options)
{
	if (str[options->it] == 'u')
	{
		ft_putnbr_unsigned_args(ap, options);
		options->it++;
	}
	else if (str[options->it] == 'X')
	{
		ft_putnbr_hex_args(ap, options);
		options->it++;
	}
	else if (str[options->it] == 'x')
	{
		ft_putnbr_hexlow_args(ap, options);
		options->it++;
	}
	else if (str[options->it] == 'p')
	{
		put_memadd_arg(ap, options);
		options->it++;
	}
}
