/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 01:58:59 by jjourdan          #+#    #+#             */
/*   Updated: 2020/12/05 15:42:18 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_separator(char *str, char *sep)
{
	while (*sep)
	{
		if (*str == *sep++)
			return (1);
	}
	return (0);
}

static size_t	ft_word_len(char *str, char *sep)
{
	size_t	i;

	i = 0;
	while (str[i] && (ft_is_separator(str + i, sep) == 0))
		i++;
	return (i);
}

static size_t	ft_word_count(char *str, char *sep)
{
	size_t i;
	size_t j;

	j = 0;
	while (*str)
	{
		while (*str && ft_is_separator(str, sep))
			str++;
		i = ft_word_len(str, sep);
		str += i;
		if (i != 0)
			j++;
	}
	return (j);
}

static char		*ft_word_copy(char *src, size_t n)
{
	char *dest;

	if (!(dest = malloc((n + 1) * sizeof(char))))
		return (NULL);
	dest[n] = '\0';
	while (n--)
		dest[n] = src[n];
	return (dest);
}

char			**ft_my_split(char *str, char *charset)
{
	char	**c;
	size_t	size;
	size_t	i;
	size_t	j;

	size = ft_word_count(str, charset);
	if (!(c = malloc((size + 1) * sizeof(char *))))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		while (*str && ft_is_separator(str, charset))
			str++;
		j = ft_word_len(str, charset);
		c[i] = ft_word_copy(str, j);
		str += j;
	}
	c[size] = 0;
	return (c);
}
