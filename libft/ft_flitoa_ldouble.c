/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flitoa_ldouble.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:42:18 by esormune          #+#    #+#             */
/*   Updated: 2021/02/24 17:44:22 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static char	*ft_get_units(long double nb)
{
	char	*str;
	size_t	units;

	units = (size_t)nb;
	str = ft_itoa_ulong_base((unsigned long long)units, 10);
	return (str);
}

static char	*ft_get_decimals(long double nb, int prec)
{
	char	*str;
	size_t	units;
	int		i;

	i = 0;
	str = ft_calloc((prec + 1), sizeof(char));
	units = (size_t)nb;
	nb = nb - units;
	while (i < prec)
	{
		nb = nb * 10;
		str[i] = (char)((int)nb + 48);
		nb = nb - (int)nb;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_form_str(char *str1, char *str2, int neg, int zeros)
{
	char	buf[100 + 1];
	int		i;

	ft_bzero(buf, (100 + 1));
	if (neg == -1)
		ft_strcat(buf, "-");
	ft_strcat(buf, str1);
	ft_strcat(buf, ".");
	i = (int)ft_strlen(buf);
	while (zeros > 0)
	{
		buf[neg++] = '0';
		zeros--;
	}
	ft_strcat(buf, str2);
	free(str1);
	free(str2);
	return (ft_strdup(buf));
}

char		*ft_flitoa_ldouble(long double nb, int prec)
{
	char	*str1;
	char	*str2;
	char	*new;
	int		neg;
	int		zeros;

	if (nb == (1.0 / 0.0))
		return (ft_strdup("inf"));
	else if (nb == (1.0 / -0.0))
		return (ft_strdup("-inf"));
	else if (nb != nb)
		return (ft_strdup("nan"));
	neg = (nb < 0) ? -1 : 1;
	if (nb == 0 && ft_is_neg((double)nb) == 1)
		neg = -1;
	if (neg == -1)
		nb = nb * (-1);
	nb = ft_brounding(nb, prec);
	if (prec <= 0)
		return (ft_itoa(((int)nb) * neg));
	str1 = ft_get_units(nb);
	str2 = ft_get_decimals(nb, prec);
	zeros = prec - (int)ft_strlen(str2);
	new = ft_form_str(str1, str2, neg, zeros);
	return (new);
}
