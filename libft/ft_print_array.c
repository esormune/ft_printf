/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 00:58:24 by esormune          #+#    #+#             */
/*   Updated: 2021/02/09 01:02:33 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_print_array(char **res)
{
	int i;

	i = 0;
	while (res[i] != NULL)
	{
		ft_putendl(res[i]);
		i++;
	}
}
