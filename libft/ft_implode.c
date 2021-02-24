/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_implode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:53:25 by esormune          #+#    #+#             */
/*   Updated: 2021/02/15 18:53:36 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_implode(char **str)
{
	size_t	size;
	char	*new;
	int		i;

	i = 0;
	size = 0;
	while (str[i] != NULL)
	{
		size = size + ft_strlen(str[i]);
		i++;
	}
	if (!(new = ft_calloc(sizeof(char), size + 1)))
		return (NULL);
	i = 0;
	while (str[i] != NULL)
	{
		ft_strcat(new, str[i]);
		i++;
	}
	return (new);
}
