/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:56:51 by mpaci             #+#    #+#             */
/*   Updated: 2021/03/22 17:56:54 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_weirdo(t_nbr *nbr, t_options *options)
{
	if (options->precision == 0 && nbr->num == 0)
	{
		nbr->num_len = 0;
		if (options->width)
		{
			while (options->width-- > nbr->num_len)
			{
				ft_putchar(' ');
				options->res++;
			}
		}
		initialize_struct(options);
		return (1);
	}
	return (0);
}

void	sparey(t_nbr *nbr, t_options *options)
{
	if (options->precision > nbr->num_len)
	{
		nbr->n_zero = options->precision - nbr->num_len;
		nbr->num_len = options->precision;
	}
	if (nbr->num < 0)
		nbr->num_len++;
	options->res += nbr->num_len;
	if (options->width > nbr->num_len)
		options->res += (options->width - nbr->num_len);
	if (!options->minus)
	{
		if (nbr->num < 0 && options->zero)
		{
			ft_putchar('-');
			nbr->num *= -1;
		}
		while (options->width-- > nbr->num_len)
			ft_putchar((options->zero ? '0' : ' '));
	}
	if (nbr->num < 0 && nbr->num != -2147483648)
	{
		ft_putchar('-');
		nbr->num *= -1;
	}
}

void	ft_putnbr_args(va_list args, t_options *options)
{
	t_nbr	*nbr;
	t_nbr	nb;

	nbr = &nb;
	nbr->num = va_arg(args, long int);
	nbr->n_zero = 0;
	nbr->num_len = ft_digits_counter(nbr->num);
	if (options->precision > -1)
		options->zero = 0;
	if (ft_weirdo(nbr, options))
		return ;
	sparey(nbr, options);
	while (nbr->n_zero-- > 0)
		ft_putchar('0');
	ft_putnbr(nbr->num);
	if (options->minus)
	{
		while (options->width-- > nbr->num_len)
			ft_putchar(' ');
	}
	initialize_struct(options);
}
