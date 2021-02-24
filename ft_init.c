/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 19:40:55 by esormune          #+#    #+#             */
/*   Updated: 2021/02/18 20:02:04 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Initialises and mallocs space for the printf struct, including
** the array of strings and the length array.
*/

t_printf	*ft_init(char *str)
{
	t_printf	*res;
	int			i;

	if (!(res = (t_printf *)malloc(sizeof(t_printf))))
		return (NULL);
	if (!(res->strings = ft_split(str)))
		return (NULL);
	i = 0;
	while (res->strings[i] != NULL)
		i++;
	if (!(res->lengths = (size_t *)malloc(sizeof(size_t) * (i))))
		return (NULL);
	return (res);
}

/*
** Frees all allocated memory from the t_printf struct. In other words, the
** reverse of init.
*/

void		ft_rev_init(t_printf *res)
{
	ft_free_array(res->strings);
	free(res->lengths);
	free(res);
}
