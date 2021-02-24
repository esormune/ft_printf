/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:52:20 by esormune          #+#    #+#             */
/*   Updated: 2021/02/18 23:01:16 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Assign the width of str to data.
*/

void	ft_width(char *str, t_flags *data)
{
	int		n;
	int		x;

	n = ft_atoi(&(str[data->index]));
	data->nwidth = n;
	x = ft_numlength(data->nwidth);
	data->index += x - 1;
}

/*
** Returns the width or precision based on which is larger. Space for
** plus and ' ' is reserved for instances that precision is the
** larger one.
*/

int		ft_check_width(char *nb, t_flags *data)
{
	int	neg;
	int	space;

	if (nb[0] == '-')
		neg = 1;
	else
		neg = 0;
	if (neg == 0 && (data->space == 1 || data->plus == 1))
		space = 1;
	else
		space = 0;
	if (data->nprecis + neg + space > data->nwidth)
		return (data->nprecis + neg + space);
	return (data->nwidth);
}

/*
** Check width for hex. Needs to take into consideration that if prec is
** operative, you need to add the value of hash. If it's width,
** no hash needed.
*/

int		ft_check_hex_width(t_flags *data)
{
	if (data->nprecis > data->nwidth)
		return (data->nprecis + data->hash);
	return (data->nwidth);
}

/*
** Checks pointer width. Pointers need + 2 to precision, not width.
*/

int		ft_check_ptr_width(t_flags *data)
{
	if (data->nprecis + 2 > data->nwidth)
		return (data->nprecis + 2);
	return (data->nwidth);
}
