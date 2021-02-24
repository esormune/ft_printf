/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:31:54 by esormune          #+#    #+#             */
/*   Updated: 2021/02/20 15:52:21 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns an int as string. IF NEED BE, check length etc here.
** Sends a fully complete itoa string for next function to copy.
** Sends which one is bigger from strlen or width for buf size if not minused.
*/

char	*ft_int(t_flags *data, va_list list)
{
	char	*new;
	char	*nb;
	int		space;
	int		width;

	if (data->length == '0')
		nb = ft_itoa(va_arg(list, int));
	else
		nb = ft_check_length(data, list);
	if (ft_strcmp("0", nb) == 0 && data->nprecis == -1)
	{
		free(nb);
		nb = ft_strdup("");
	}
	space = ft_space(nb, data);
	width = ft_check_width(nb, data);
	new = ft_int_cont(nb, data, space, width);
	free(nb);
	return (new);
}

/*
** Continuation of ft_int.
*/

char	*ft_int_cont(char *nb, t_flags *data, int space, int width)
{
	char	*new;
	int		size;
	int		neg;

	neg = (nb[0] == '-') ? 1 : 0;
	if (((int)ft_strlen(nb) + space) < width)
		size = width;
	else
		size = ((int)ft_strlen(nb) + space);
	if (data->minus == 1)
	{
		if (neg == 1)
			new = ft_minus_neg_nb(size, nb, data);
		else
			new = ft_minus_nb(size, nb, data);
	}
	else
		new = ft_nb(size, nb, data);
	data->len = ft_strlen(new);
	return (new);
}
