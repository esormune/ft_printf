/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 20:25:29 by esormune          #+#    #+#             */
/*   Updated: 2021/02/19 20:27:27 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_putnstr_fd(char *str, size_t size, int fd)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}
