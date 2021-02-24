/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:00:17 by esormune          #+#    #+#             */
/*   Updated: 2021/02/24 19:27:26 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns string when it's left aligned and a number.
*/

char	*ft_minus_nb(int size, char *nb, t_flags *data)
{
	char	*buf;
	int		i;
	int		x;

	i = 0;
	x = 0;
	buf = ft_calloc(size + 1, sizeof(char));
	if (data->plus == 1)
		buf[i++] = '+';
	else if (data->space == 1)
		buf[i++] = ' ';
	while (x++ < (data->nprecis - (int)ft_strlen(nb)))
		buf[i++] = '0';
	ft_strcat(buf, nb);
	i = ft_strlen(buf);
	if (data->hash == 1 && data->nprecis == -1 && (data->spec == 'f' ||
		data->spec == 'F'))
		buf[i++] = '.';
	while (i < data->nwidth && data->zero == 0)
		buf[i++] = ' ';
	while (i < data->nwidth && data->zero == 1)
		buf[i++] = '0';
	return (buf);
}

/*
** Returns a number string when the number is negative and left-aligned.
*/

char	*ft_minus_neg_nb(int size, char *nb, t_flags *data)
{
	char	*buf;
	int		i;
	int		x;

	i = 0;
	x = 0;
	buf = ft_calloc(size + 1, sizeof(char));
	buf[i++] = '-';
	while (x++ < (data->nprecis - ((int)ft_strlen(nb) - 1)))
		buf[i++] = '0';
	ft_strcat(buf, &nb[1]);
	if (data->hash == 1 && data->nprecis == -1 && (data->spec == 'f' ||
		data->spec == 'F'))
		buf[i++] = '.';
	i = ft_strlen(buf);
	while (i < data->nwidth && data->zero == 0)
		buf[i++] = ' ';
	while (i < data->nwidth && data->zero == 1)
		buf[i++] = '0';
	buf[i] = '\0';
	return (buf);
}

/*
** Starts off the return of nb string when right aligned.
*/

char	*ft_nb(int size, char *nb, t_flags *data)
{
	char	*buf;
	int		neg;
	int		x;
	int		space;

	neg = 0;
	if (nb[0] == '-' && ft_strlen(nb) > 1)
		neg = 1;
	space = 0;
	if (neg == 1 || data->space == 1 || data->plus == 1)
		space = 1;
	buf = ft_calloc((size + 1), sizeof(char));
	x = (int)ft_strlen(nb);
	while (neg == 0 && x >= 0)
		buf[size--] = nb[x--];
	while (neg == 1 && x >= 1)
		buf[size--] = nb[x--];
	x = 0;
	while (size >= 0 && (x++ < (data->nprecis - (int)ft_strlen(nb) + neg)))
		buf[size--] = '0';
	if (size == 0 && neg == 1)
		buf[size--] = '-';
	while (data->zero == 1 && space == 1 && size >= 1)
		buf[size--] = '0';
	return (ft_return_nb(buf, data, neg, size));
}

/*
** Returns string when it's right aligned and a number.
*/

char	*ft_return_nb(char *buf, t_flags *data, int neg, int size)
{
	if (data->space == 1 && neg == 0)
		buf[size--] = ' ';
	if (data->plus == 1 && neg == 0)
		buf[size--] = '+';
	if (size >= 0 && neg == 1)
		buf[size--] = '-';
	while (data->zero == 1 && size >= 0)
		buf[size--] = '0';
	while (size >= 0 && data->zero == 0)
		buf[size--] = ' ';
	return (buf);
}
