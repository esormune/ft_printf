/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 12:57:22 by esormune          #+#    #+#             */
/*   Updated: 2020/06/22 15:46:19 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				res;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (us1[i] == us2[i] && us1[i] != '\0' && us2[i] != '\0')
		i++;
	res = us1[i] - us2[i];
	return (res);
}
