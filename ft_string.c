/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:25:50 by esormune          #+#    #+#             */
/*   Updated: 2021/02/17 13:56:17 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns a string to the function.
*/

char	*ft_string(t_flags *data, va_list list)
{
	char	*new;
	char	*str;
	char	*prec_str;
	size_t	size;

	str = va_arg(list, char*);
	if (!str)
		return (ft_null_string(data));
	if (data->nprecis == -1)
		prec_str = ft_strdup("");
	else
		prec_str = ft_prec_str(str, data->nprecis);
	size = ft_strlen(prec_str);
	new = ft_string_cont(data, prec_str, size);
	return (new);
}

/*
** Continuation of ft_string.
*/

char	*ft_string_cont(t_flags *data, char *prec_str, size_t size)
{
	char	*new;

	if (size >= (size_t)data->nwidth)
		new = ft_strdup(prec_str);
	else if (data->minus == 1)
	{
		if (size < (size_t)data->nwidth)
			size = (size_t)data->nwidth;
		new = ft_minus_str(size, prec_str, data);
	}
	else
	{
		if (size < (size_t)data->nwidth)
			size = (size_t)data->nwidth;
		new = ft_return_str(size, prec_str, data);
	}
	free(prec_str);
	data->len = ft_strlen(new);
	return (new);
}

/*
** Returns a string correct with the precision flag.
*/

char	*ft_prec_str(char *str, int prec)
{
	char	buf[prec + 1];
	int		i;

	i = 0;
	if (prec == 0)
		return (ft_strdup(str));
	while (i < prec)
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (ft_strdup(buf));
}

/*
** Returns string when left aligned.
*/

char	*ft_minus_str(size_t size, char *str, t_flags *data)
{
	char	*new;
	char	buf[size + 1];
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	ft_bzero(buf, (size + 1));
	ft_strcat(buf, str);
	i = i + len;
	while (i < (size_t)data->nwidth && data->zero == 0)
		buf[i++] = ' ';
	while (i < (size_t)data->nwidth && data->zero == 1)
		buf[i++] = '0';
	buf[i] = '\0';
	new = ft_strdup(buf);
	return (new);
}

/*
** Returns string when right aligned.
*/

char	*ft_return_str(size_t size, char *str, t_flags *data)
{
	char	buf[size + 1];
	size_t	len;
	size_t	diff;
	size_t	i;

	i = 0;
	len = ft_strlen(str);
	diff = size - len;
	ft_bzero(buf, (size + 1));
	while (diff > 0)
	{
		if (data->zero == 1)
			buf[i++] = '0';
		else
			buf[i++] = ' ';
		diff--;
	}
	ft_strcat(buf, str);
	i = i + len;
	buf[i] = '\0';
	return (ft_strdup(buf));
}
