/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg_pow_ten.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:56:21 by esormune          #+#    #+#             */
/*   Updated: 2021/02/01 15:56:47 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

long double	ft_neg_pow_ten(long double nb, int pow)
{
	int			i;
	long double	res;

	i = pow;
	res = nb;
	while (i > 0)
	{
		res = res * 0.1;
		i--;
	}
	return (res);
}
