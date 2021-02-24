/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_neg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:21:59 by esormune          #+#    #+#             */
/*   Updated: 2021/02/19 17:25:04 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_is_neg(double nb)
{
	unsigned long long	*x;
	int					ret;

	x = (unsigned long long*)&nb;
	ret = (*x >> 63);
	if (ret == 1)
		return (1);
	return (0);
}
