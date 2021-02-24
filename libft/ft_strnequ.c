/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:10:17 by esormune          #+#    #+#             */
/*   Updated: 2020/06/29 14:28:38 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	if (n <= 0)
		return (1);
	while (i < (n - 1) && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if ((s1[i] - s2[i]) == 0)
		return (1);
	else
		return (0);
}
