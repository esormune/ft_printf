/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 14:07:50 by esormune          #+#    #+#             */
/*   Updated: 2020/06/25 17:28:40 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	negcoef;

	i = 0;
	res = 0;
	negcoef = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		negcoef = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] < 48 || str[i] > 57)
		return (0);
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * negcoef);
}
