/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:24:03 by esormune          #+#    #+#             */
/*   Updated: 2021/02/24 19:31:08 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns a char as string.
*/

char	*ft_char(t_flags *data, va_list list)
{
	char	*new;
	char	str;
	size_t	size;

	str = (char)va_arg(list, int);
	if (!str)
		return (ft_null_char(data));
	if (data->nwidth != 0)
		size = (size_t)data->nwidth;
	else
		size = 1;
	if (data->minus == 1)
		new = ft_minus_nb(size, &str, data);
	else
		new = ft_nb(size, &str, data);
	data->len = ft_strlen(new);
	return (new);
}

/*
** Deals with the instance of NULL character.
*/

char	*ft_null_char(t_flags *data)
{
	char	*new;
	char	*str;
	size_t	size;

	str = ft_strdup("\0");
	if (data->nwidth != 0)
		size = (size_t)data->nwidth;
	else
		size = 1;
	if (data->minus == 1)
		new = ft_minus_null_char(size, str, data);
	else
		new = ft_return_null_char(size, str, data);
	free(str);
	data->len = size;
	return (new);
}

/*
** Returns NULL char when right aligned.
*/

char	*ft_return_null_char(size_t size, char *str, t_flags *data)
{
	char	buf[size + 1];
	size_t	diff;
	size_t	i;

	i = 0;
	diff = size - 1;
	ft_bzero(buf, (size + 1));
	while (diff >= 1)
	{
		if (data->zero == 1)
			buf[i++] = '0';
		else
			buf[i++] = ' ';
		diff--;
	}
	ft_strncat(buf, str, 1);
	i++;
	buf[i] = '\0';
	return (ft_strndup(buf, i));
}

/*
** Returns null char when it's left aligned.
*/

char	*ft_minus_null_char(int size, char *str, t_flags *data)
{
	char	*new;
	char	buf[size + 1];
	int		i;
	int		x;

	x = 0;
	ft_bzero(buf, size + 1);
	ft_strncat(buf, str, 1);
	i = 1;
	while (i < (data->nwidth))
		buf[i++] = ' ';
	buf[i] = '\0';
	new = ft_strndup(buf, size + 1);
	return (new);
}
