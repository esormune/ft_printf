/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 16:15:00 by esormune          #+#    #+#             */
/*   Updated: 2020/06/13 16:26:20 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
