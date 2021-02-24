/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:48:24 by esormune          #+#    #+#             */
/*   Updated: 2021/02/18 19:53:32 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks the float precision and sets it as -1 if the precision
** has been specifically set at 0 to avoid defaulting.
*/

void	ft_check_f_precis(char *str, t_flags *data)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == '0' || ft_isdigit(str[i + 1]) == 0)
			{
				data->nprecis = -1;
				return ;
			}
		}
		i++;
	}
}

/*
** Returns 1 if an extra space is needed and a 0 if not.
*/

int		ft_space(char *nb, t_flags *data)
{
	if (nb[0] != '-' && data->zero == 1 &&
		(data->space == 1 || data->plus == 1))
		return (1);
	if (nb[0] != '-' && (data->space == 1 || data->plus == 1))
		return (1);
	return (0);
}

/*
** Returns correct itoa for length modifier of number.
*/

char	*ft_check_length(t_flags *data, va_list list)
{
	int	n;

	if (data->length == 's')
	{
		n = (signed char)va_arg(list, int);
		return (ft_itoa(n));
	}
	else if (data->length == 'h')
	{
		n = (short)va_arg(list, int);
		return (ft_itoa(n));
	}
	else if (data->length == 'l')
		return (ft_itoa_llong_base(va_arg(list, long), 10));
	else if (data->length == 'o')
		return (ft_itoa_llong_base((va_arg(list, long long)), 10));
	else if (data->length == 'j')
		return (ft_itoa_intmax_base((va_arg(list, intmax_t)), 10));
	else if (data->length == 'z')
		return (ft_itoa_llong_base((long long)
			(va_arg(list, size_t)), 10));
	else
		return (NULL);
}
