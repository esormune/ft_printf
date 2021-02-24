/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:15:19 by esormune          #+#    #+#             */
/*   Updated: 2020/06/29 21:35:34 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	ft_wordcount(char *str, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			flag = 1;
		if (str[i] != c && str[i] != '\0')
		{
			if (flag == 1)
			{
				count++;
				flag = 0;
			}
		}
		i++;
	}
	return (count);
}

static char	**ft_create_array(char *s, char c, int wc)
{
	int		i;
	int		j;
	int		start;
	char	**dest;

	if (!(dest = (char**)malloc(sizeof(char*) * (wc + 1))))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < wc && s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		dest[j] = ft_strsub(s, start, (i - start));
		i++;
	}
	dest[j] = NULL;
	return (dest);
}

char		**ft_strsplit(char const *s, char c)
{
	int		wc;
	char	**dest;

	if (!s || !c)
		return (NULL);
	wc = ft_wordcount((char*)s, c);
	dest = ft_create_array((char*)s, c, wc);
	if (!dest)
		return (NULL);
	return (dest);
}
