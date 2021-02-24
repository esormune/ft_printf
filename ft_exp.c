/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:28:10 by esormune          #+#    #+#             */
/*   Updated: 2021/02/20 15:49:44 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns a scientific notation as string.
*/

char	*ft_exponent(t_flags *data, va_list list)
{
	char	*new;
	char	*nb;
	int		prec;
	int		space;

	if (data->nprecis == 0)
		prec = 6;
	else
		prec = data->nprecis;
	if (data->length == 'L')
		nb = ft_itoa_exp(va_arg(list, long double), prec);
	else
		nb = ft_itoa_exp((long double)va_arg(list, double), prec);
	space = ft_space(nb, data);
	new = ft_exp_cont(data, nb, space);
	free(nb);
	return (new);
}

/*
** Continuation of ft_exponent.
*/

char	*ft_exp_cont(t_flags *data, char *nb, int space)
{
	char	*new;
	int		size;

	if (((int)ft_strlen(nb) + space) < data->nwidth)
		size = data->nwidth;
	else
		size = (int)ft_strlen(nb) + space;
	if (data->minus == 1)
		new = ft_minus_nb(size, nb, data);
	else
		new = ft_return_exp(size, nb, data);
	if (data->spec == 'E')
		ft_toupper_str(new);
	data->len = ft_strlen(new);
	return (new);
}

/*
** Returns a scientific notation as string when right aligned.
*/

char	*ft_return_exp(int size, char *nb, t_flags *data)
{
	char	*buf;
	int		neg;
	int		x;

	buf = ft_calloc((size + 1), sizeof(char));
	neg = (nb[0] == '-') ? 1 : 0;
	x = (int)ft_strlen(nb);
	buf[size + 1] = '\0';
	while (neg == 0 && x >= 0)
		buf[size--] = nb[x--];
	while (neg == 1 && x >= 1)
		buf[size--] = nb[x--];
	x = 0;
	if (data->zero == 1 && (neg == 1 || data->space == 1 || data->plus == 1))
	{
		while (size >= 1 && (x++ <= (data->nwidth - (int)ft_strlen(nb))))
			buf[size--] = '0';
	}
	if (data->zero == 1 && neg == 0 && data->space == 0 && data->plus == 0)
	{
		while (size >= 0 && (x++ <= (data->nwidth - (int)ft_strlen(nb))))
			buf[size--] = '0';
	}
	return (ft_return_exp_cont(size, buf, data, neg));
}

/*
** Continuation of ft_return_exp. Returns buffer.
*/

char	*ft_return_exp_cont(int size, char *buf, t_flags *data, int neg)
{
	if (data->plus == 0 && data->space == 0 && neg == 0 && data->zero == 1)
		buf[size--] = '0';
	if (data->space == 1 && neg == 0)
		buf[size--] = ' ';
	if (data->plus == 1 && neg == 0)
		buf[size--] = '+';
	if (neg == 1)
		buf[size--] = '-';
	while (size >= 0)
		buf[size--] = ' ';
	return (buf);
}
