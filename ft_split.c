/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:40:02 by esormune          #+#    #+#             */
/*   Updated: 2021/02/18 22:09:08 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks for parse ending character.
*/

int			ft_spec(char c)
{
	char	*spec;
	int		i;

	i = 0;
	spec = "diuoxXfFeEcsp%b";
	while (spec[i] != '\0')
	{
		if (c == spec[i])
			return (1);
		else
			i++;
	}
	return (0);
}

/*
** Checks character for validity as a digit, flag, or an ending character.
*/

int			ft_valid(char c)
{
	char	*flag;
	int		i;

	i = 0;
	flag = "0+-#. *lhzjL";
	if (ft_isdigit(c) == 1)
		return (1);
	while (flag[i] != '\0')
	{
		if (c == flag[i])
			return (1);
		else
			i++;
	}
	if (ft_spec(c) == 1)
		return (1);
	return (0);
}

/*
** Counts size necessary for array.
*/

static int	ft_count_size(char *str, size_t i, int count)
{
	while (str[i] != '\0')
	{
		if (str[i] != '\0' && str[i] != '%')
		{
			count++;
			while (str[i] != '\0' && str[i] != '%')
				i++;
		}
		else if (str[i] == '%')
		{
			i++;
			count++;
			while (str[i] != '\0' && ft_spec(str[i]) == 0 &&
				ft_valid(str[i]) == 1)
				i++;
			if (ft_spec(str[i]) == 1)
				i++;
			else if (ft_valid(str[i] == 0))
				i++;
		}
	}
	return (count);
}

/*
** Actually splits the string into an array.
*/

static char	**ft_return_split(char **res, char *str, int count)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (j < count && str[i] != '\0')
	{
		start = i;
		while (str[i] != '\0' && str[i] != '%')
			i++;
		if (start != i)
			res[j++] = ft_strsub(str, start, (i - start));
		if (str[i] == '%')
		{
			start = i++;
			while (str[i] != '\0' && ft_spec(str[i]) == 0 && ft_valid(str[i]))
				i++;
			if (ft_spec(str[i]) == 1)
				i++;
			res[j++] = ft_strsub(str, start, (i - start));
		}
	}
	res[j] = NULL;
	return (res);
}

/*
** Find the variable calls in the string & split string into
** an array of strings. It calls a function that will check the size
** of needed array as well as a function that changes variable calls
** into their string to be printed.
*/

char		**ft_split(char *str)
{
	char	**res;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	count = ft_count_size(str, i, count);
	if (!(res = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	res = ft_return_split(res, str, count);
	return (res);
}
