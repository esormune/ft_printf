/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 13:29:00 by esormune          #+#    #+#             */
/*   Updated: 2020/10/29 19:16:07 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_numlength(int nb)
{
	int	size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb / 10 != nb)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}
