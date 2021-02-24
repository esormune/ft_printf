/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esormune <esormune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 13:14:57 by esormune          #+#    #+#             */
/*   Updated: 2020/06/29 21:35:53 by esormune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	ft_check_if_last(const char *s, int i)
{
	while (ft_is_whitespace(s[i]))
		i++;
	if (s[i] == '\0')
		return (1);
	else
		return (0);
}

static int	ft_count_len(const char *s)
{
	int first;
	int i;
	int	temp;

	i = 0;
	first = 0;
	while (ft_is_whitespace(s[i++]))
		first++;
	while (s[i] != '\0')
	{
		temp = 1;
		if (ft_is_whitespace(s[i + temp] == 1))
		{
			while (ft_is_whitespace(s[i + temp] == 1))
				temp++;
			if ((i + temp) == '\0')
				return (i - first);
			else if (ft_is_whitespace(s[i + temp] == 0))
				i = i + temp;
		}
		i++;
	}
	return (i - first);
}

static char	*ft_create_string(char *s, int len)
{
	int		i;
	int		x;
	char	*dest;

	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	x = 0;
	while (ft_is_whitespace(s[i]))
		i++;
	while (s[i] != '\0')
	{
		if (ft_check_if_last(s, i) == 1)
			break ;
		dest[x] = s[i];
		i++;
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

char		*ft_strtrim(char const *s)
{
	int		len;
	char	*dest;

	if (!s)
		return (NULL);
	len = ft_count_len(s);
	dest = ft_create_string((char*)s, len);
	if (!dest)
		return (NULL);
	return (dest);
}
