/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_word_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:33:55 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/16 14:36:58 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_cub3d_pass_digit(char **str)
{
	while (*str[0] == ' ')
		(*str)++;
	while (ft_isdigit(*str[0]))
		(*str)++;
	return (SUCCESS);
}

int		ft_cub3d_go_next_word(char **str, char sep, char end)
{
	while ((*str[0] != 0) && (*str[0] != sep) && (*str[0] != end))
		(*str) += 1;
	if (*str[0] == 0)
		return (-1);
	else if (*str[0] == end)
	{
		while (*str[0] == end)
			(*str) += 1;
		return (1);
	}
	while (*str[0] == sep)
		(*str) += 1;
	return (0);
}

char	*ft_cub3d_get_first_word(char **str, char sep, char end)
{
	char	*word;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while ((*str[0] != 0) && (*str[0] != sep) && (*str[0] != end))
	{
		(*str) += 1;
		i++;
	}
	j = i;
	if (!(word = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	while (i >= 0)
	{
		if (i >= 0)
			(*str) -= 1;
		i--;
		if (i >= 0)
			word[i] = *str[0];
	}
	(*str) += j;
	if (j > 0)
		(*str) += 1;
	return (word);
}

int		ft_cub3d_is_charset(char **map, char *charset)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	k;
	int		return_value;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			k = -1;
			return_value = MAP_INVALID_CHAR;
			while (charset[++k])
			{
				if (map[i][j] == charset[k])
					return_value = SUCCESS;
			}
			if (return_value != SUCCESS)
				return (return_value);
		}
	}
	return (SUCCESS);
}

int		ft_cub3d_get_starting_pos(t_map_params *map_params, \
								char *charset)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	while (map_params->map[++i])
	{
		j = -1;
		while (map_params->map[i][++j])
		{
			if ((ft_cub3d_start_is_charset(map_params, i, j, charset)) \
														!= SUCCESS)
				return (MAP_INVALID_POS);
		}
	}
	return (SUCCESS);
}
