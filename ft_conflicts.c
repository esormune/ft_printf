/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conflicts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:48:14 by esormune          #+#    #+#             */
/*   Updated: 2021/02/18 19:57:01 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Check if the char is a length signifier.
*/

int		ft_is_len(char c)
{
	char	*str;
	int		i;

	i = 0;
	str = "hljztL";
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*
** Checks for the existence of a "." or a ".0" precision with some specs,
** changes precision flag to -1. For the case of a * flag, the sprecis is
** also changed to -1 to indicate that the length has been specified to 0
** and therefore will is not to be confused with a negative precision from
** user input when it is checked later. Checks for a .0[0000...]
** precision, so that f.ex. .0000 will return -1 but .0009 will have
** a precision of 9.
*/

void	ft_check_zero(char *str, t_flags *data)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.' && str[i + 1] == '0')
		{
			i = i + 2;
			while (str[i] != '\0' && ft_isdigit(str[i]))
			{
				if (str[i] != '0')
					return ;
				i++;
			}
			data->nprecis = -1;
			return ;
		}
		if (str[i] == '.' && data->sprecis == 1)
			data->sprecis = -1;
		if (str[i] == '.')
			data->nprecis = -1;
		i++;
	}
}

/*
** Continuation of conflict check.
*/

void	ft_conflicts_cont(t_flags *data)
{
	if (data->spec == 's' || data->spec == 'b' || data->spec == 'p')
	{
		data->plus = 0;
		data->space = 0;
		if (data->spec != 's' && data->spec != 'p')
			data->nprecis = 0;
		if (data->spec != 's')
			data->zero = 0;
		data->length = '0';
	}
	if (data->minus == 1)
		data->zero = 0;
	if ((data->spec == 'f' || data->spec == 'F') && data->length != 'L')
		data->length = '0';
	if ((data->spec == 'f' || data->spec == 'F') && data->minus == 1)
		data->zero = 0;
	return ;
}

/*
** Function checks for conflicts and changes the data to avoid conflicts.
*/

void	ft_conflicts(t_flags *data)
{
	if (data->sprecis == 1 && data->nprecis < 0)
		data->nprecis = 0;
	if (data->swidth == 1 && data->nwidth < 0)
	{
		data->minus = 1;
		data->nwidth = data->nwidth * (-1);
	}
	if (data->plus == 1 && data->space == 1)
		data->space = 0;
	if (data->spec != 'f' && data->spec != 'F' &&
		data->spec != 'e' && data->spec != 'E' &&
		data->nprecis != 0 && data->zero == 1)
		data->zero = 0;
	return (ft_conflicts_cont(data));
}
