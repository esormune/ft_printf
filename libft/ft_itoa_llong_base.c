/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llong_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:48:20 by esormune          #+#    #+#             */
/*   Updated: 2021/02/19 16:17:43 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static char	*ft_save(long long nb, int neg, int base)
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

char		*ft_itoa_llong_base(long long nb, int base)
{
	char		*save;
	int			neg;

	if (base < 2 || base > 16)
		return (NULL);
	if (nb == (-9223372036854775807 - 1))
		return (ft_strdup("-9223372036854775808"));
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
