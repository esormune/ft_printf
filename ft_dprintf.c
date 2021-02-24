/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 20:19:07 by esormune          #+#    #+#             */
/*   Updated: 2021/02/19 21:44:59 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Prints the string onto the file descriptor. Returns size for dprintf
** return.
*/

static int	ft_drev_split(t_printf *res, int fd)
{
	char	*str;
	size_t	size;
	int		i;
	int		x;
	int		y;

	i = 0;
	size = 0;
	while (res->strings[i] != NULL)
		size = size + res->lengths[i++];
	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (-1);
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
	ft_putnstr_fd(str, y, fd);
	free(str);
	return (y);
}

/*
** A variation of printf that prints the output onto the file descriptor
** instead of STDOUT.
*/

int			ft_dprintf(int fd, const char *format, ...)
{
	t_flags		*data;
	t_printf	*res;
	va_list		list;
	int			ret;

	if (!(data = (t_flags *)malloc(sizeof(t_flags))))
		return (-1);
	ft_reset(data);
	if (!(res = ft_init((char*)format)))
		return (-1);
	va_start(list, format);
	res->strings = ft_next(res, data, list);
	ret = ft_drev_split(res, fd);
	ft_rev_init(res);
	va_end(list);
	free(data);
	return (ret);
}
