/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:31:32 by esormune          #+#    #+#             */
/*   Updated: 2021/02/24 17:08:37 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns an unsigned int as string.
*/

char	*ft_u_int(t_flags *data, va_list list)
{
	char	*new;
	char	*nb;
	int		width;

	if (data->length == '0')
		nb = ft_itoa_ulong_base((unsigned long long)
		(va_arg(list, unsigned int)), 10);
	else
		nb = ft_check_ulength(data, list);
	if (data->nprecis == -1 && ft_strcmp("0", nb) == 0)
	{
		free(nb);
		nb = ft_strdup("");
	}
	width = ft_check_width(nb, data);
	new = ft_u_int_cont(data, nb, width);
	free(nb);
	return (new);
}

/*
** Continuation of ft_u_int function.
*/

char	*ft_u_int_cont(t_flags *data, char *nb, int width)
{
	char	*new;
	int		size;

	if ((int)ft_strlen(nb) < width)
		size = width;
	else
		size = (int)ft_strlen(nb);
	if (data->minus == 1)
		new = ft_minus_nb(size, nb, data);
	else
		new = ft_nb(size, nb, data);
	data->len = ft_strlen(new);
	return (new);
}

/*
** Returns correct unsigned itoa for length modifier of number.
*/

char	*ft_check_ulength(t_flags *data, va_list list)
{
	int		n;

	if (data->length == 's')
	{
		n = (unsigned char)va_arg(list, int);
		return (ft_itoa(n));
	}
	else if (data->length == 'h')
	{
		n = (unsigned short)va_arg(list, int);
		return (ft_itoa(n));
	}
	else if (data->length == 'l')
		return (ft_itoa_ulong_base((unsigned long long)
		(va_arg(list, unsigned long)), 10));
	else if (data->length == 'o')
		return (ft_itoa_ulong_base((va_arg(list, unsigned long long)), 10));
	else if (data->length == 'j')
		return (ft_itoa_uintmax_base((va_arg(list, uintmax_t)), 10));
	else if (data->length == 'z')
		return (ft_itoa_ulong_base((unsigned long long)
		(va_arg(list, size_t)), 10));
	else
		return (NULL);
}
