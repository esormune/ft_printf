/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:15:27 by esormune          #+#    #+#             */
/*   Updated: 2020/07/02 13:43:43 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*p;

	i = ft_strlen(str) + 1;
	p = (char*)str;
	while (i--)
	{
		if (p[i] == (char)c)
			return (&p[i]);
	}
	return (NULL);
}
