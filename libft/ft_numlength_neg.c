/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlength_neg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:04:34 by esormune          #+#    #+#             */
/*   Updated: 2020/11/03 16:07:25 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_numlength_neg(int nb)
{
	int	size;

	size = 0;
	if (nb < 0)
		size++;
	if (nb == 0)
		return (1);
	while (nb / 10 != nb)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}
