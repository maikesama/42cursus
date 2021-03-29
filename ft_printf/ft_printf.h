/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaci <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:46:30 by mpaci             #+#    #+#             */
/*   Updated: 2021/03/22 18:46:32 by mpaci            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef unsigned long int	t_size;
typedef struct	s_options
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int res;
	int it;
	int	id;
}				t_options;

typedef struct	s_nbr
{
	int num;
	int n_zero;
	int num_len;
}				t_nbr;

void			min_zero(const char *str, t_options *options);
void			sparxtu(char *s, t_options *options, int n);
void			sparx(char *s, t_options *options, int n);
int				min(int i, t_options *option);
void			sparring(char *s, t_options *options, int n);
void			search_all(const char *str, va_list ap, t_options *options);
void			fukkino(t_options *options);
void			initialize_struct_two(t_options *options);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			wid_conversion(const char *str, int start, t_options *options);
void			prec_conversion(const char *str, int start, t_options *options);
void			search_flag_one(const char *str, va_list ap,
				t_options *options);
void			search_flag_two(const char *str, va_list ap,
				t_options *options);
int				search_char_one(const char *str, va_list ap,
				t_options *options);
void			search_char_two(const char *str, va_list ap,
				t_options *options);
void			ft_putnbr_args(va_list args, t_options *options);
void			ft_putnbr_hex_args(va_list args, t_options *options);
void			ft_putnbr_hexlow_args(va_list args, t_options *options);
unsigned int	ft_digits_counter_hex(unsigned long int n);
void			sparehex_third(char *s, t_options *options);
void			sparehex_sec(char *s, t_options *options);
void			sparehex_first(char *s, t_options *options);
void			ft_putnbr_unsigned_args(va_list args, t_options *options);
char			*ft_itoa_hexlow(unsigned long int n);
void			ft_putstr_hex(char *s, t_options *options);
char			*ft_convert_hexlow(char *str, unsigned long int n,
				unsigned int len);
unsigned int	ft_digits_counter_hexp(unsigned long long int n);
void			put_memadd_arg(va_list args, t_options *options);
int				ft_digits_counter(int n);
char			*ft_convert(char *str, long int n, int len);
char			*ft_itoa(long int n);
void			initialize_struct(t_options *options);
int				ft_atoi_flag(const char *str, int start);
void			*ft_memset(void *b, int c, size_t n);
void			ft_bzero(void *str, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_putstr_args(va_list args, t_options *options);
int				ft_strlen(const char *str);
void			ft_putchar_args(va_list args, t_options	*options);
void			ft_putperc(char c, t_options *options);
void			sparechar(t_options *options);
int				ft_printf(const char *str, ...);

#endif
