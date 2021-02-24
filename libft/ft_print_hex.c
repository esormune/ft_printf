/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:48:40 by esormune          #+#    #+#             */
/*   Updated: 2020/08/17 16:07:04 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_print_hex(size_t nb)
{
	char	*str;

	str = "0123456789ABCDEF";
	if (nb > 16)
		ft_print_hex(nb / 16);
	ft_putchar((str[nb % 16]));
}
