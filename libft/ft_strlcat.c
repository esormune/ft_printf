/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:49:58 by esormune          #+#    #+#             */
/*   Updated: 2020/07/04 23:28:28 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;
	long	max;

	i = 0;
	j = ft_strlen(dest);
	len = (ft_strlen(dest) + ft_strlen(src));
	max = (long)dstsize - (long)ft_strlen(dest) - 1;
	if (dstsize == 0)
		return (ft_strlen(src) + dstsize);
	while (src[i] != '\0' && (long)i < max)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	if (dstsize < ft_strlen(dest))
		return (ft_strlen(src) + dstsize);
	return (len);
}
