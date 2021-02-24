/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:51:55 by esormune          #+#    #+#             */
/*   Updated: 2021/02/15 15:52:52 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putnstr(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putchar(str[i]);
		i++;
	}
}
