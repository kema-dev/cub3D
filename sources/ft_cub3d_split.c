/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 10:46:53 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/22 10:22:36 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char			**ft_cub3d_tab_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t		ft_cub3d_get_nb_strs(char const *s, char c)
{
	size_t	i;
	size_t	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			i++;
			if (s[i] == c)
				i = ft_cub3d_nb_strs_2(s, i, c);
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void			ft_cub3d_get_next_str(char **next_str, \
						size_t *next_str_len, char c)
{
	size_t i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	if (**next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

char				**ft_cub3d_split(char const *s, char c)
{
	char			**tab;
	char			*next_str;
	size_t			next_str_len;
	size_t			nb_strs;
	size_t			i;

	if (!s)
		return (NULL);
	nb_strs = ft_cub3d_get_nb_strs(s, c);
	if (!(tab = ft_calloc(sizeof(char *), (nb_strs + 1))))
		return (NULL);
	i = 0;
	next_str = (char *)s;
	next_str_len = 0;
	while (i < nb_strs)
	{
		if (next_str[0] == c)
			break ;
		ft_cub3d_get_next_str(&next_str, &next_str_len, c);
		if (!(tab[i] = ft_calloc(sizeof(char), (next_str_len + 1))))
			return (ft_cub3d_tab_free(tab));
		ft_strlcpy(tab[i], next_str, next_str_len + 1);
		i++;
	}
	return (tab);
}

int					ft_cub3d_field_is_charset(char *field, char *charset)
{
	ssize_t	i;
	ssize_t	k;
	int		dual;
	int		return_value;

	dual = 0;
	i = -1;
	while (field[++i])
	{
		return_value = MAP_INVALID_CHAR;
		if ((field[i] == 'N') || (field[i] == 'S') \
			|| (field[i] == 'E') || (field[i] == 'W'))
			dual++;
		k = -1;
		while (charset[++k])
		{
			if (field[i] == charset[k])
				return_value = SUCCESS;
		}
		if (return_value != SUCCESS)
			return (return_value);
	}
	if (dual != 1)
		return (MAP_NO_STARTING_POS);
	return (SUCCESS);
}
