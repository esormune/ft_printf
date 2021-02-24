/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:05:36 by esormune          #+#    #+#             */
/*   Updated: 2021/02/18 22:58:17 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Returns a string with the percent specifier. Very similar to string
** and therefore uses its function here.
*/

char	*ft_percent(t_flags *data)
{
	char	*new;
	char	*prec_str;
	size_t	size;

	prec_str = ft_prec_str("%", data->nprecis);
	size = ft_strlen(prec_str);
	new = ft_string_cont(data, prec_str, size);
	return (new);
}
