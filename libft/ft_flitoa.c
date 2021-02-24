/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:00:18 by esormune          #+#    #+#             */
/*   Updated: 2021/02/24 17:43:10 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static char	*ft_get_units(double nb)
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

static char	*ft_neg_zero(int prec)
{
	char	buf[100];
	int		i;
	int		x;

	i = 0;
	x = 0;
	ft_bzero(buf, 100);
	if (prec <= 0)
		return (ft_strdup("-0"));
	ft_strcat(buf, "-0.");
	i = i + 3;
	while (x < prec && i < 100)
	{
		buf[i++] = '0';
		x++;
	}
	return (ft_strdup(buf));
}

static char	*ft_flitoa_cont(long double nb, char *buf, int neg, int prec)
{
	char	*str1;
	char	*str2;
	int		len;
	int		zeros;

	str1 = ft_get_units(nb);
	str2 = ft_get_decimals(nb, prec);
	zeros = prec - (int)ft_strlen(str2);
	if (neg == -1)
		ft_strcat(buf, "-");
	ft_strcat(buf, str1);
	ft_strcat(buf, ".");
	len = (int)ft_strlen(buf);
	while (zeros > 0)
	{
		buf[len++] = '0';
		zeros--;
	}
	ft_strcat(buf, str2);
	free(str1);
	free(str2);
	return (buf);
}

char		*ft_flitoa(double nb, int prec)
{
	char		*buf;
	int			size;
	int			neg;
	long double	x;

	if (nb == (1.0 / 0.0))
		return (ft_strdup("inf"));
	else if (nb == (1.0 / -0.0))
		return (ft_strdup("-inf"));
	else if (nb != nb)
		return (ft_strdup("nan"));
	else if (nb == 0 && ft_is_neg(nb) == 1)
		return (ft_neg_zero(prec));
	size = (ft_numlength_neg((int)nb) + prec);
	neg = (nb < 0) ? -1 : 1;
	if (neg == -1)
		nb = nb * (-1);
	x = ft_brounding((long double)nb, prec);
	if (prec <= 0)
		return (ft_itoa_base(((int)x * neg), 10));
	buf = ft_calloc((size + 3), sizeof(char));
	return (ft_flitoa_cont(x, buf, neg, prec));
}
