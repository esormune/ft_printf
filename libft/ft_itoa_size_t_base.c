/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_size_t_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:39:55 by esormune          #+#    #+#             */
/*   Updated: 2020/12/11 16:18:09 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static char	*ft_save(size_t nb, int base)
{
	char	*str;
	char	*save;
	char	temp[64 + 1];
	int		i;
	int		x;

	i = 0;
	x = 0;
	str = "0123456789ABCDEF";
	while (nb > 0)
	{
		temp[i] = str[nb % base];
		nb = nb / base;
		i++;
	}
	temp[i] = '\0';
	if (!(save = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = i - 1;
	while (i >= 0)
		save[x++] = temp[i--];
	save[x] = '\0';
	return (save);
}

char		*ft_itoa_size_t_base(size_t nb, int base)
{
	char		*save;

	if (base < 2 || base > 16)
		return (NULL);
	if (nb == 0)
	{
		if (!(save = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		save[0] = '0';
		save[1] = '\0';
		return (save);
	}
	return (ft_save(nb, base));
}
