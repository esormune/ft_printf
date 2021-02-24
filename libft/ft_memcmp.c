/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:48:03 by esormune          #+#    #+#             */
/*   Updated: 2020/07/02 13:32:14 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				res;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char*)s1;
	p2 = (unsigned char*)s2;
	if (n <= 0)
		return (0);
	while (i < (n - 1) && p1[i] == p2[i])
		i++;
	res = p1[i] - p2[i];
	return (res);
}
