/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:18:36 by esormune          #+#    #+#             */
/*   Updated: 2021/02/20 15:51:35 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/includes/libft.h"

/*
** for length, "ll" translates to "o" and "hh" to "s"
*/

typedef struct	s_flags
{
	int			plus;
	int			minus;
	int			space;
	int			hash;
	int			zero;
	int			nwidth;
	int			swidth;
	int			nprecis;
	int			sprecis;
	char		length;
	char		spec;
	size_t		index;
	size_t		len;
}				t_flags;

typedef struct	s_printf
{
	char		**strings;
	size_t		*lengths;
}				t_printf;

int				ft_printf(const char *str, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

t_printf		*ft_init(char *str);
void			ft_rev_init(t_printf *res);
void			ft_reset(t_flags *data);
char			**ft_split(char *str);
int				ft_rev_split(t_printf *res);
int				ft_spec(char c);
char			**ft_next(t_printf *res, t_flags *data, va_list list);
void			ft_parser(char *str, t_flags *data, va_list list);
void			ft_print_struct(t_flags *data);
char			*ft_convert(char *str, t_flags *data, va_list list);
char			*ft_convert_cont(t_flags *data, va_list list);
void			ft_conflicts(t_flags *data);
int				ft_is_len(char c);
void			ft_width(char *str, t_flags *data);
int				ft_space(char *nb, t_flags *data);

char			*ft_int(t_flags *data, va_list list);
char			*ft_int_cont(char *nb, t_flags *data, int space, int width);
char			*ft_u_int(t_flags *data, va_list list);
char			*ft_u_int_cont(t_flags *data, char *nb, int width);
char			*ft_octal(t_flags *data, va_list list);
char			*ft_octal_cont(t_flags *data, char *nb, int width);
char			*ft_hex(t_flags *data, va_list list);
char			*ft_hex_cont(t_flags *data, char *nb, int width);
char			*ft_binary(t_flags *data, va_list list);
char			*ft_string(t_flags *data, va_list list);
char			*ft_string_cont(t_flags *data, char *prec_str, size_t size);
char			*ft_char(t_flags *data, va_list list);
char			*ft_float(t_flags *data, va_list list);
char			*ft_float_cont(char *nb, int dot, t_flags *data);
char			*ft_exponent(t_flags *data, va_list list);
char			*ft_exp_cont(t_flags *data, char *nb, int space);
char			*ft_pointer(t_flags *data, va_list list);
char			*ft_percent(t_flags *data);

char			*ft_minus_nb(int size, char *nb, t_flags *data);
char			*ft_minus_neg_nb(int size, char *nb, t_flags *data);
char			*ft_minus_str(size_t size, char *str, t_flags *data);
char			*ft_nb(int size, char *nb, t_flags *data);
char			*ft_return_nb(char *buf, t_flags *data, int neg, int size);
char			*ft_return_str(size_t size, char *str, t_flags *data);
char			*ft_prec_str(char *str, int prec);
char			*ft_minus_ptr(size_t size, char *str, t_flags *data);
char			*ft_return_ptr(size_t size, char *str, t_flags *data);
int				ft_check_ptr_width(t_flags *data);
char			*ft_null_string(t_flags *data);
char			*ft_null_char(t_flags *data);
char			*ft_return_null_char(size_t size, char *str, t_flags *data);
char			*ft_minus_null_char(int size, char *nb, t_flags *data);
char			*ft_return_exp(int size, char *nb, t_flags *data);
char			*ft_return_exp_cont(int size, char *buf, t_flags *data,
					int neg);
char			*ft_return_float(int size, char *nb, t_flags *data);
char			*ft_ret_f_cont(char *buf, t_flags *d, int neg, int size);
char			*ft_return_hex(int size, char *nb, t_flags *data);
char			*ft_minus_hex(char *nb, t_flags *data);
char			*ft_return_oct(int size, char *nb, t_flags *data);
char			*ft_minus_oct(char *nb, t_flags *data);
int				ft_check_width(char *nb, t_flags *data);
int				ft_check_hex_width(t_flags *data);

char			*ft_check_length(t_flags *data, va_list list);
char			*ft_check_ulength(t_flags *data, va_list list);
char			*ft_check_olength(t_flags *data, va_list list);
char			*ft_check_hexlength(t_flags *data, va_list list);
char			*ft_check_blength(t_flags *data, va_list list);
void			ft_check_zero(char *str, t_flags *data);
void			ft_check_f_precis(char *str, t_flags *data);

#endif
