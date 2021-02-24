/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:06:09 by esormune          #+#    #+#             */
/*   Updated: 2020/06/16 13:06:18 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*dest;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len] != '\0')
		len++;
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = f(s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
