/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:22:18 by esormune          #+#    #+#             */
/*   Updated: 2021/02/18 22:59:16 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Implodes the array back into a string with consideration to NULL chars
** and therefore uses defined lengths instead of "until '\0'". Prints the
** string. Returns value for printf.
*/

int	ft_rev_split(t_printf *res)
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
	ft_putnstr(str, y);
	free(str);
	return (y);
}
