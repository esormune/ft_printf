/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:22:40 by esormune          #+#    #+#             */
/*   Updated: 2021/02/18 22:56:12 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Assigns precision for star flag.
*/

static void	ft_assign_sprecis(t_flags *data, va_list list)
{
	data->sprecis = 1;
	data->nprecis = va_arg(list, int);
}

/*
** Checks the precision required by the string.
*/

static void	ft_precision(char *str, t_flags *data, va_list list)
{
	int	n;
	int	x;

	data->index++;
	if (str[data->index] == '*')
		ft_assign_sprecis(data, list);
	else if (ft_isdigit(str[data->index]) == 0)
		data->index--;
	else if (str[data->index] == '0' && ft_isdigit(str[data->index + 1]) == 1)
	{
		n = ft_atoi(&(str[data->index]));
		data->nprecis = n;
		while (ft_isdigit(str[data->index]) == 1)
			data->index++;
		data->index = data->index - 1;
	}
	else
	{
		n = ft_atoi(&(str[data->index]));
		data->nprecis = n;
		x = ft_numlength(data->nprecis);
		data->index += x - 1;
	}
}

/*
** Checks for a length flag and assigns it. ll translates to 'o' (long long) &
** hh to 's' (unsigned & signed chars).
*/

void		ft_length(char *str, t_flags *data)
{
	if (str[data->index + 1] == 'h')
	{
		data->length = 's';
		data->index++;
	}
	else if (str[data->index + 1] == 'l')
	{
		data->length = 'o';
		data->index++;
	}
	else
		data->length = str[data->index];
}

/*
** A simple function to assign wildcard width.
*/

static void	ft_assign_swidth(t_flags *data, va_list list)
{
	data->nwidth = va_arg(list, int);
	data->swidth = 1;
}

/*
** This function parses the data in the string into the t_flag data.
*/

void		ft_parser(char *str, t_flags *data, va_list list)
{
	data->index++;
	while (str[data->index] != '\0')
	{
		if (str[data->index] == '-')
			data->minus = 1;
		else if (str[data->index] == '+')
			data->plus = 1;
		else if (str[data->index] == ' ')
			data->space = 1;
		else if (str[data->index] == '#')
			data->hash = 1;
		else if (str[data->index] == '0')
			data->zero = 1;
		else if (str[data->index] == '*')
			ft_assign_swidth(data, list);
		else if (ft_isdigit(str[data->index]))
			ft_width(str, data);
		else if (str[data->index] == '.')
			ft_precision(str, data, list);
		else if (ft_is_len(str[data->index]) == 1)
			ft_length(str, data);
		else if (ft_spec(str[data->index]) == 1)
			data->spec = str[data->index];
		data->index++;
	}
}
