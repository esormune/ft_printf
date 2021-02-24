/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:00:32 by esormune          #+#    #+#             */
/*   Updated: 2021/02/18 20:02:44 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Deals with the instance of a NULL string.
*/

char	*ft_null_string(t_flags *data)
{
	char	*new;
	char	*str;
	char	*prec_str;
	size_t	size;

	str = ft_strdup("(null)");
	if (data->nprecis == -1)
		prec_str = ft_strdup("");
	else
		prec_str = ft_prec_str(str, data->nprecis);
	free(str);
	size = ft_strlen(prec_str);
	new = ft_string_cont(data, prec_str, size);
	return (new);
}
