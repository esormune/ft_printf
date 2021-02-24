/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:57:58 by esormune          #+#    #+#             */
/*   Updated: 2021/02/19 22:47:43 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns size of string. Used for eventual sprintf return value.
*/

static int	ft_sprintf_size(t_printf *res)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (res->strings[i] != NULL)
		size = size + res->lengths[i++];
	return (size);
}

/*
** Implodes the array back into a string with consideration to NULL chars
** and therefore uses defined lengths instead of "until '\0'". Saves the
** string into given pointer. Returns value for sprintf.
*/

static char	*ft_srev_split(t_printf *res, int size)
{
	char	*str;
	int		i;
	int		x;
	int		y;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	y = 0;
	while (res->strings[i] != NULL)
	{
		x = 0;
		while ((size_t)x < res->lengths[i])
			str[y++] = res->strings[i][x++];
		i++;
	}
	str[y] = '\0';
	return (str);
}

/*
** Sprintf function; like printf, but returns the output to a string.
*/

int			ft_sprintf(char *str, const char *format, ...)
{
	t_flags		*data;
	t_printf	*res;
	char		*new;
	va_list		list;
	int			ret;

	if (!(data = (t_flags *)malloc(sizeof(t_flags))))
		return (-1);
	ft_reset(data);
	if (!(res = ft_init((char*)format)))
		return (-1);
	va_start(list, format);
	res->strings = ft_next(res, data, list);
	ret = ft_sprintf_size(res);
	new = ft_srev_split(res, ret);
	ft_bzero(str, ft_strlen(str));
	ft_strncpy(str, new, ret);
	free(new);
	ft_rev_init(res);
	va_end(list);
	free(data);
	return (ret);
}
