/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:29:00 by esormune          #+#    #+#             */
/*   Updated: 2021/02/24 16:57:43 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns an octal as string.
*/

char	*ft_octal(t_flags *data, va_list list)
{
	char	*new;
	char	*nb;
	int		width;

	if (data->length == '0')
		nb = ft_itoa_ulong_base((unsigned long long)
			(va_arg(list, unsigned int)), 8);
	else
		nb = ft_check_olength(data, list);
	if (data->nprecis == -1 && data->hash == 0 &&
		ft_strcmp("0", nb) == 0)
	{
		free(nb);
		nb = ft_strdup("");
	}
	if (ft_strcmp(nb, "0") == 0 && data->hash == 1)
		data->hash = 0;
	width = ft_check_width(nb, data);
	new = ft_octal_cont(data, nb, width);
	free(nb);
	return (new);
}

/*
** Continuation of ft_octal function.
*/

char	*ft_octal_cont(t_flags *data, char *nb, int width)
{
	char	*new;
	int		size;

	if (data->minus == 1)
		new = ft_minus_oct(nb, data);
	else
	{
		if ((int)ft_strlen(nb) + data->hash < width)
			size = width;
		else
			size = (int)ft_strlen(nb) + data->hash;
		new = ft_return_oct(size, nb, data);
	}
	data->len = ft_strlen(new);
	return (new);
}

/*
** Returns correct itoa for length modifier of octal.
*/

char	*ft_check_olength(t_flags *data, va_list list)
{
	int		n;

	if (data->length == 's')
	{
		n = (unsigned char)va_arg(list, int);
		return (ft_itoa_base(n, 8));
	}
	else if (data->length == 'h')
	{
		n = (unsigned short)va_arg(list, int);
		return (ft_itoa_base(n, 8));
	}
	else if (data->length == 'l')
		return (ft_itoa_ulong_base((unsigned long long)
			(va_arg(list, unsigned long)), 8));
	else if (data->length == 'o')
		return (ft_itoa_ulong_base((va_arg(list, unsigned long long)), 8));
	else if (data->length == 'j')
		return (ft_itoa_uintmax_base((va_arg(list, uintmax_t)), 8));
	else if (data->length == 'z')
		return (ft_itoa_ulong_base((unsigned long long)
			(va_arg(list, size_t)), 8));
	else
		return (NULL);
}

/*
** Returns string when it's left aligned and a number.
*/

char	*ft_minus_oct(char *nb, t_flags *data)
{
	char	*new;
	char	buf[100];
	int		i;
	int		x;

	i = 0;
	x = 0;
	ft_bzero(buf, 100);
	if (data->hash != 0)
		buf[i++] = '0';
	while (x++ < (data->nprecis - (int)ft_strlen(nb) - data->hash))
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

/*
** Returns string when it's right aligned and a number.
*/

char	*ft_return_oct(int size, char *nb, t_flags *data)
{
	char	buf[size + 1];
	int		x;

	x = (int)ft_strlen(nb);
	ft_bzero(buf, (size + 1));
	buf[size + 1] = '\0';
	while (x >= 0)
		buf[size--] = nb[x--];
	x = 0;
	if (data->hash != 0)
		buf[size--] = '0';
	while (size >= 0 &&
			(x++ < (data->nprecis - (int)ft_strlen(nb) - data->hash)))
		buf[size--] = '0';
	while (data->nprecis == 0 && size >= 0 && data->zero == 1)
		buf[size--] = '0';
	while (size >= 0 && data->zero == 0)
		buf[size--] = ' ';
	return (ft_strdup(buf));
}
