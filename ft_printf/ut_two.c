/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut_two.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:34:46 by mpaci             #+#    #+#             */
/*   Updated: 2021/03/22 18:34:48 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_flag(const char *str, int start)
{
	int	val;
	int	accumulator;

	val = 0;
	accumulator = 0;
	while (str[start] >= '0' && str[start] <= '9' && *str)
	{
		val = (str[start] - '0');
		accumulator = (accumulator * 10) + val;
		start++;
	}
	return (accumulator);
}

void	initialize_struct(t_options *options)
{
	options->width = 0;
	options->precision = -1;
	options->minus = 0;
	options->zero = 0;
}

int		ft_digits_counter(int n)
{
	int		needed;

	needed = 0;
	if (!n)
		return (1);
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = n / 10;
		needed++;
	}
	return (needed);
}

char	*ft_convert(char *str, long int n, int len)
{
	if (n < 0)
	{
		*str = '-';
		n *= -1;
	}
	if (n == 0)
	{
		*str = '0';
		return (str);
	}
	while (n > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (str);
}
