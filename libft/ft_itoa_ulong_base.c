/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 01:33:02 by esormune          #+#    #+#             */
/*   Updated: 2021/02/09 01:33:32 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static char	*ft_save(unsigned long long nb, int base)
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
	if (!(save = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = i - 1;
	while (i >= 0)
		save[x++] = temp[i--];
	save[x] = '\0';
	return (save);
}

char		*ft_itoa_ulong_base(unsigned long long nb, int base)
{
	char	*save;

	if (base < 2 || base > 16)
		return (NULL);
	if (nb == 0)
	{
		if (!(save = (char *)malloc(sizeof(char) * 2)))
			return (NULL);
		save[0] = '0';
		save[1] = '\0';
		return (save);
	}
	return (ft_save(nb, base));
}
