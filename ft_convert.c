/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:04:11 by esormune          #+#    #+#             */
/*   Updated: 2021/02/18 22:58:33 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Frees the old string and creates the replacement.
*/

char	*ft_convert(char *str, t_flags *data, va_list list)
{
	char *string;

	free(str);
	if (data->spec == 'd' || data->spec == 'i')
		string = ft_int(data, list);
	else if (data->spec == 'u')
		string = ft_u_int(data, list);
	else if (data->spec == 'o')
		string = ft_octal(data, list);
	else if (data->spec == 'x' || data->spec == 'X')
		string = ft_hex(data, list);
	else if (data->spec == 'c')
		string = ft_char(data, list);
	else if (data->spec == 's')
		string = ft_string(data, list);
	else
		return (ft_convert_cont(data, list));
	return (string);
}

/*
** Continuation of ft_convert.
*/

char	*ft_convert_cont(t_flags *data, va_list list)
{
	char *string;

	if (data->spec == 'f' || data->spec == 'F')
		string = ft_float(data, list);
	else if (data->spec == 'e' || data->spec == 'E')
		string = ft_exponent(data, list);
	else if (data->spec == 'p')
		string = ft_pointer(data, list);
	else if (data->spec == '%')
		string = ft_percent(data);
	else if (data->spec == 'b')
		string = ft_binary(data, list);
	else
		return (ft_strdup(""));
	return (string);
}
