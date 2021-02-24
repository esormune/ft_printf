/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:55:56 by esormune          #+#    #+#             */
/*   Updated: 2020/07/02 13:42:02 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*p;

	p = (char*)str;
	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == (char)c)
			return (&p[i]);
		i++;
	}
	if (!c && p[i] == '\0')
		return (&p[i]);
	return (NULL);
}
