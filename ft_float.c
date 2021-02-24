/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:26:22 by esormune          #+#    #+#             */
/*   Updated: 2021/02/24 19:12:54 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Helper function to null irrelevant data for cases of inf, -inf, or NaN.
** Returns 0 to reset the space for "dot", as it is not needed.
*/

static int	ft_nan_reset(char *nb, t_flags *data)
{
	data->zero = 0;
	if (!ft_strcmp("nan", nb))
	{
		data->plus = 0;
		data->space = 0;
	}
	return (0);
}

/*
** Returns a float as string. If the number returned is NaN or Inf, it will
** be dealt with as a string.
*/

char		*ft_float(t_flags *data, va_list list)
{
	char	*new;
	char	*nb;
	int		prec;
	int		dot;

	if (data->nprecis == 0)
		prec = 6;
	else
		prec = data->nprecis;
	if (data->length == 'L')
		nb = ft_flitoa_ldouble(va_arg(list, long double), prec);
	else
		nb = ft_flitoa(va_arg(list, double), prec);
	dot = 0;
	if (data->hash == 1 && data->nprecis < 0)
		dot = 1;
	if (!ft_strcmp("inf", nb) || !ft_strcmp("-inf", nb) ||
		!ft_strcmp("nan", nb))
		dot = ft_nan_reset(nb, data);
	new = ft_float_cont(nb, dot, data);
	free(nb);
	return (new);
}

/*
** Continuation of ft_float.
*/

char		*ft_float_cont(char *nb, int dot, t_flags *data)
{
	char	*new;
	int		size;
	int		neg;
	int		space;

	neg = (nb[0] == '-') ? 1 : 0;
	space = 0;
	if (neg == 0 && (data->space == 1 || data->plus == 1))
		space = 1;
	if ((int)ft_strlen(nb) + dot + space < data->nwidth)
		size = data->nwidth;
	else
		size = ((int)ft_strlen(nb) + dot + space);
	if (data->minus == 1)
	{
		if (neg == 1)
			new = ft_minus_neg_nb(size, nb, data);
		else
			new = ft_minus_nb(size, nb, data);
	}
	else
		new = ft_return_float(size, nb, data);
	data->len = ft_strlen(new);
	return (new);
}

/*
** Returns a float as string when right aligned. Get a space here, you'll
** need plus, space.
*/

char		*ft_return_float(int size, char *nb, t_flags *d)
{
	char	*buf;
	int		neg;
	int		x;

	neg = (nb[0] == '-') ? 1 : 0;
	x = (int)ft_strlen(nb) - 1;
	buf = ft_calloc((size + 1), sizeof(char));
	size--;
	if (d->hash == 1 && d->nprecis == -1 && ft_strcmp("inf", nb) != 0 &&
		ft_strcmp("-inf", nb) != 0 && ft_strcmp("nan", nb) != 0)
		buf[size--] = '.';
	while (neg == 0 && x >= 0)
		buf[size--] = nb[x--];
	while (neg == 1 && x >= 1)
		buf[size--] = nb[x--];
	x = 0;
	while (d->zero == 1 && size > 0 &&
		(x++ <= (d->nwidth - ((int)ft_strlen(nb) + neg))))
		buf[size--] = '0';
	return (ft_ret_f_cont(buf, d, neg, size));
}

/*
** Continuation of ft_return_float.
*/

char		*ft_ret_f_cont(char *buf, t_flags *d, int neg, int size)
{
	if (size >= 0 && d->plus == 0 && d->space == 0 && neg == 0 &&
		d->zero == 1)
		buf[size--] = '0';
	if (size >= 0 && d->space == 1 && neg == 0)
		buf[size--] = ' ';
	if (size >= 0 && d->plus == 1 && neg == 0)
		buf[size--] = '+';
	if (size >= 0 && neg == 1)
		buf[size--] = '-';
	while (size >= 0)
		buf[size--] = ' ';
	return (buf);
}
