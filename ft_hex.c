/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:29:28 by esormune          #+#    #+#             */
/*   Updated: 2021/02/18 23:00:28 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns a hex as string.
*/

char	*ft_hex(t_flags *data, va_list list)
{
	char	*new;
	char	*nb;
	int		width;

	if (data->length == '0')
		nb = ft_itoa_ulong_base((unsigned long long)
			(va_arg(list, unsigned int)), 16);
	else
		nb = ft_check_hexlength(data, list);
	if (ft_strcmp("0", nb) == 0)
		data->hash = 0;
	if (data->nprecis == -1 && ft_strcmp("0", nb) == 0)
	{
		free(nb);
		nb = ft_strdup("");
	}
	width = ft_check_hex_width(data);
	new = ft_hex_cont(data, nb, width);
	free(nb);
	return (new);
}

/*
** Stupid extra function because of norms; continuation of ft_hex.
*/

char	*ft_hex_cont(t_flags *data, char *nb, int width)
{
	char	*new;
	int		size;

	if (data->minus == 1)
		new = ft_minus_hex(nb, data);
	else
	{
		if (((int)ft_strlen(nb) + data->hash) < width)
			size = width;
		else
			size = (int)ft_strlen(nb) + data->hash;
		new = ft_return_hex(size, nb, data);
	}
	if (data->spec == 'x')
		ft_tolower_str(new);
	data->len = ft_strlen(new);
	return (new);
}

/*
** Returns correct itoa for length modifier of hex.
*/

char	*ft_check_hexlength(t_flags *data, va_list list)
{
	int		n;

	if (data->length == 's')
	{
		n = (unsigned char)va_arg(list, int);
		return (ft_itoa_base(n, 16));
	}
	else if (data->length == 'h')
	{
		n = (unsigned short)va_arg(list, int);
		return (ft_itoa_base(n, 16));
	}
	else if (data->length == 'l')
		return (ft_itoa_ulong_base((unsigned long long)
			(va_arg(list, unsigned long)), 16));
	else if (data->length == 'o')
		return (ft_itoa_ulong_base((va_arg(list, unsigned long long)), 16));
	else if (data->length == 'j')
		return (ft_itoa_uintmax_base((va_arg(list, uintmax_t)), 16));
	else if (data->length == 'z')
		return (ft_itoa_ulong_base((unsigned long long)
			(va_arg(list, size_t)), 16));
	else
		return (NULL);
}

/*
** Returns a hex as string when right aligned.
*/

char	*ft_return_hex(int size, char *nb, t_flags *d)
{
	char	buf[size + 1];
	int		x;

	x = (int)ft_strlen(nb);
	ft_bzero(buf, (size + 1));
	buf[size + 1] = '\0';
	while (x >= 0)
		buf[size--] = nb[x--];
	x = 0;
	while (x++ < (d->nprecis - (int)ft_strlen(nb)))
		buf[size--] = '0';
	x = 0;
	if (d->zero == 1)
	{
		while (size >= 0 && (x++ < (d->nwidth - (int)ft_strlen(nb) - d->hash)))
			buf[size--] = '0';
	}
	if (d->hash != 0)
	{
		buf[size--] = 'X';
		buf[size--] = '0';
	}
	while (size >= 0)
		buf[size--] = ' ';
	return (ft_strdup(buf));
}

/*
** Returns hex when it's left aligned.
*/

char	*ft_minus_hex(char *nb, t_flags *data)
{
	char	*new;
	char	buf[100];
	int		i;
	int		x;

	i = 0;
	x = 0;
	ft_bzero(buf, 100);
	if (data->hash != 0)
	{
		ft_strcat(buf, "0X");
		i = i + 2;
	}
	while (x++ < (data->nprecis - (int)ft_strlen(nb)))
		buf[i++] = '0';
	ft_strcat(buf, nb);
	i = i + (ft_strlen(nb));
	while (i < data->nwidth && data->zero == 0)
		buf[i++] = ' ';
	while (i < data->nwidth && data->zero == 1)
		buf[i++] = '0';
	buf[i] = '\0';
	new = ft_strdup(buf);
	return (new);
}
