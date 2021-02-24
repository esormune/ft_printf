/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:49:20 by esormune          #+#    #+#             */
/*   Updated: 2020/08/17 16:10:45 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	print_bits(unsigned char octet)
{
	char *str;

	if (!(str = ft_itoa_base(octet, 2)))
		return ;
	ft_putstr(str);
}
