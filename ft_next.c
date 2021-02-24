/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:16:47 by esormune          #+#    #+#             */
/*   Updated: 2021/02/18 22:26:02 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This function finds the strings that need changing and calls the function
** that parses the string into t_flag data. Then it will call a converting
** function.
*/

char	**ft_next(t_printf *res, t_flags *data, va_list list)
{
	int	i;

	i = 0;
	while (res->strings[i] != NULL)
	{
		if (res->strings[i][0] == '%')
		{
			ft_parser(res->strings[i], data, list);
			if (data->nprecis == 0 && (data->spec != 'e' && data->spec != 'E'
				&& data->spec != 'c' && data->spec != '%'))
				ft_check_zero(res->strings[i], data);
			if (data->hash == 1 && (data->spec == 'x' || data->spec == 'X'))
				data->hash = 2;
			ft_conflicts(data);
			res->strings[i] = ft_convert(res->strings[i], data, list);
			res->lengths[i] = data->len;
			ft_reset(data);
		}
		else
			res->lengths[i] = ft_strlen(res->strings[i]);
		i++;
	}
	return (res->strings);
}
