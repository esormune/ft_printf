/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:43:15 by esormune          #+#    #+#             */
/*   Updated: 2020/06/16 12:43:59 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	while (i <= size)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
