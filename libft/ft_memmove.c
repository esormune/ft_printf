/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:51:35 by esormune          #+#    #+#             */
/*   Updated: 2020/07/02 13:32:39 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memmove(void *to, const void *from, size_t len)
{
	size_t	i;
	char	*cto;
	char	*cfrom;

	if (!to && !from)
		return (NULL);
	cto = (char*)to;
	cfrom = (char*)from;
	if (from < to)
	{
		i = len;
		while (i-- > 0)
			cto[i] = cfrom[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			cto[i] = cfrom[i];
			i++;
		}
	}
	return (to);
}
