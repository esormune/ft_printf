/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:54:02 by esormune          #+#    #+#             */
/*   Updated: 2020/07/14 22:25:37 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_realloc(void *ptr, size_t oldsize, size_t newsize)
{
	char	*new;

	if (!ptr)
	{
		if (!(new = (char*)malloc(sizeof(char) * newsize)))
			return (NULL);
	}
	if ((!newsize && ptr))
	{
		if (!(new = (char*)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (new);
	}
	if (newsize <= oldsize)
		return (ptr);
	if (!(new = ft_memalloc(newsize)))
		return (NULL);
	ft_memcpy(new, ptr, oldsize);
	ft_memdel(&ptr);
	return (new);
}
