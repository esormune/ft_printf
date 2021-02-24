/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:17:48 by esormune          #+#    #+#             */
/*   Updated: 2021/02/19 23:11:19 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Resets the struct for further use.
*/

void	ft_reset(t_flags *data)
{
	data->plus = 0;
	data->minus = 0;
	data->space = 0;
	data->hash = 0;
	data->zero = 0;
	data->nwidth = 0;
	data->swidth = 0;
	data->nprecis = 0;
	data->sprecis = 0;
	data->length = '0';
	data->spec = '0';
	data->index = 0;
	data->len = 0;
}

/*
** Allocates memory for struct. Frees it in the end.
** Begins parsing call. Has output call.
*/

int		ft_printf(const char *str, ...)
{
	t_flags		*data;
	t_printf	*res;
	va_list		list;
	int			ret;

	if (!(data = (t_flags *)malloc(sizeof(t_flags))))
		return (-1);
	ft_reset(data);
	if (!(res = ft_init((char*)str)))
		return (-1);
	va_start(list, str);
	res->strings = ft_next(res, data, list);
	ret = ft_rev_split(res);
	ft_rev_init(res);
	va_end(list);
	free(data);
	return (ret);
}
