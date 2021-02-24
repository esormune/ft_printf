/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:55:19 by esormune          #+#    #+#             */
/*   Updated: 2020/08/17 16:16:58 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_itoa(int n)
{
	char	*str;

	if (!(str = ft_itoa_base(n, 10)))
		return (NULL);
	return (str);
}
