/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:27:29 by esormune          #+#    #+#             */
/*   Updated: 2021/02/18 23:01:16 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** A static function that continues ft_pointer to actually return string.
*/

static char	*ft_ptr_cont(t_flags *data, char *str, size_t size)
{
	char	*new;
	int		width;

	width = ft_check_ptr_width(data);
	if (size < (size_t)width)
		size = (size_t)width;
	if (data->minus == 1)
		new = ft_minus_ptr(size, str, data);
	else
		new = ft_return_ptr(size, str, data);
	ft_tolower_str(new);
	data->len = ft_strlen(new);
	return (new);
}

/*
** Returns a pointer as string. Prepares size for the string and gets
** pointer from va_arg.
*/

char		*ft_pointer(t_flags *data, va_list list)
{
	uintmax_t	pointer;
	size_t		size;
	char		*str;
	char		*new;

	pointer = va_arg(list, uintmax_t);
	if (!(str = ft_itoa_uintmax_base(pointer, 16)))
		return (NULL);
	if (data->nprecis == -1 && ft_strcmp(str, "0") == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	size = ft_strlen(str) + 2;
	if (data->nprecis < (int)size)
		data->nprecis = 0;
	new = ft_ptr_cont(data, str, size);
	free(str);
	return (new);
}

/*
** Returns pointer when left aligned.
*/

char		*ft_minus_ptr(size_t size, char *str, t_flags *data)
{
	char	*new;
	char	buf[size + 1];
	size_t	i;
	size_t	len;
	size_t	diff;

	i = 0;
	len = ft_strlen(str);
	ft_bzero(buf, (size + 1));
	ft_strcat(buf, "0x");
	i = i + 2;
	diff = size - len - 2;
	while (data->zero == 0 && data->nprecis > 0 && diff > 0)
	{
		buf[i++] = '0';
		diff--;
	}
	ft_strcat(buf, str);
	i = i + len;
	while (i < (size_t)data->nwidth)
		buf[i++] = ' ';
	buf[i] = '\0';
	new = ft_strdup(buf);
	return (new);
}

/*
** Returns pointer when right aligned.
*/

char		*ft_return_ptr(size_t size, char *str, t_flags *data)
{
	char	buf[size + 1];
	size_t	len;
	size_t	diff;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	diff = size - len - 2;
	ft_bzero(buf, (size + 1));
	while (data->nprecis == 0 && data->zero == 0 && diff > 0)
	{
		buf[i++] = ' ';
		diff--;
	}
	ft_strcat(buf, "0x");
	i = i + 2;
	while ((data->zero == 0 && data->nprecis > 0 && diff > 0) ||
		(data->zero == 1 && diff > 0))
	{
		buf[i++] = '0';
		diff--;
	}
	ft_strcat(buf, str);
	i = i + len;
	return (ft_strdup(buf));
}
