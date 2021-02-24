/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:48:20 by esormune          #+#    #+#             */
/*   Updated: 2021/02/19 16:15:11 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static char	*ft_save(long nb, int neg, int base)
{
	char	*str;
	char	*save;
	char	temp[32 + 1];
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
	if (neg == -1 && base == 10)
		temp[i++] = '-';
	temp[i] = '\0';
	if (!(save = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = i - 1;
	while (i >= 0)
		save[x++] = temp[i--];
	save[x] = '\0';
	return (save);
}

char		*ft_itoa_base(int value, int base)
{
	char	*save;
	long	nb;
	int		neg;

	if (base < 2 || base > 16)
		return (NULL);
	nb = value;
	neg = (nb < 0) ? -1 : 1;
	if (nb < 0)
		nb = nb * (-1);
	if (nb == 0)
	{
		if (!(save = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		save[0] = '0';
		save[1] = '\0';
		return (save);
	}
	return (ft_save(nb, neg, base));
}
