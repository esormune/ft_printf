/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:59:38 by esormune          #+#    #+#             */
/*   Updated: 2020/07/13 14:59:56 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	x;
	char	*dest;

	x = 0;
	i = 0;
	while (src[x] != '\0')
		x++;
	if (!(dest = (char*)malloc(sizeof(char) * (x + 1))))
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
