/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:30:37 by esormune          #+#    #+#             */
/*   Updated: 2021/02/20 15:48:57 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns a binary as string.
*/

char	*ft_binary(t_flags *data, va_list list)
{
	char	*new;
	char	*nb;
	int		size;

	if (data->length == '0')
		nb = ft_itoa_ulong_base((unsigned long long)
			(va_arg(list, unsigned int)), 2);
	else
		nb = ft_check_blength(data, list);
	if ((int)ft_strlen(nb) < data->nwidth)
		size = data->nwidth;
	else
		size = (int)ft_strlen(nb);
	if (data->minus == 1)
		new = ft_minus_nb(size, nb, data);
	else
		new = ft_nb(size, nb, data);
	free(nb);
	data->len = ft_strlen(new);
	return (new);
}

/*
** Returns correct itoa for length modifier of hex.
*/

char	*ft_check_blength(t_flags *data, va_list list)
{
	int	n;

	if (data->length == 's')
	{
		n = (unsigned char)va_arg(list, int);
		return (ft_itoa_base(n, 2));
	}
	else if (data->length == 'h')
	{
		n = (unsigned short)va_arg(list, int);
		return (ft_itoa_base(n, 2));
	}
	else if (data->length == 'l')
		return (ft_itoa_ulong_base((unsigned long long)
			(va_arg(list, unsigned long)), 2));
	else if (data->length == 'o')
		return (ft_itoa_ulong_base((va_arg(list, unsigned long long)), 2));
	else if (data->length == 'j')
		return (ft_itoa_uintmax_base((va_arg(list, uintmax_t)), 2));
	else if (data->length == 'z')
		return (ft_itoa_ulong_base((unsigned long long)
			(va_arg(list, size_t)), 2));
	else
		return (NULL);
}
