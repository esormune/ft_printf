/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brounding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 16:00:03 by esormune          #+#    #+#             */
/*   Updated: 2021/02/20 12:07:32 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static long double	ft_compare(long double nb, long double save,
	long double compare, int prec)
{
	if (nb > 5.0)
		save = save + (ft_neg_pow_ten(1, prec));
	else if (nb == 5)
	{
		compare = compare * (ft_pow(10, prec - 1));
		compare = (compare - (int)compare);
		compare = (compare * 10);
		if ((int)compare % 2 != 0)
			save = save + (ft_neg_pow_ten(1, prec));
	}
	return (save);
}

long double			ft_brounding(long double nb, int prec)
{
	long double	save;
	long double	compare;
	int			i;

	save = nb;
	compare = nb;
	i = 0;
	nb = nb - (intmax_t)nb;
	while (i < prec)
	{
		nb = nb * 10;
		nb = nb - (int)nb;
		i++;
	}
	nb = nb * 10;
	return (ft_compare(nb, save, compare, prec));
}
