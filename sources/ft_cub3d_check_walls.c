/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_check_walls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:26:51 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/22 16:44:05 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void						ft_cub3d_fill_test_map(char **map, \
													char **test_map)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != ' ')
				test_map[i + 1][j + 1] = map[i][j];
		}
	}
}

char						**ft_cub3d_get_test_map(char **map)
{
	int		nb_rows;
	char	**test_map;

	nb_rows = 0;
	while (map[nb_rows])
		nb_rows++;
	if (!(test_map = ft_calloc(nb_rows + 3, sizeof(char *))))
		return (NULL);
	if (!(test_map[0] = ft_calloc(ft_strlen(map[0]) + 3, sizeof(char))))
		return (NULL);
	ft_memset(test_map[0], 'X', ft_strlen(map[0]) + 2);
	if (!(test_map[nb_rows + 1] = ft_calloc(ft_strlen(map[nb_rows - 1]) \
													+ 3, sizeof(char))))
		return (NULL);
	ft_memset(test_map[nb_rows + 1], 'X', ft_strlen(map[nb_rows - 1]) + 2);
	while (--nb_rows >= 0)
	{
		if (!(test_map[nb_rows + 1] = ft_calloc(ft_strlen(map[nb_rows]) \
													+ 3, sizeof(char))))
			return (NULL);
		ft_memset(test_map[nb_rows + 1], 'X', ft_strlen(map[nb_rows]) + 2);
	}
	ft_cub3d_fill_test_map(map, test_map);
	return (test_map);
}

int							ft_cub3d_check_walls(t_map_params *map_params)
{
	char	**test_map;
	int		return_value;
	ssize_t	i;

	if (!(test_map = ft_cub3d_get_test_map(map_params->map)))
		return (MALLOC_FAIL);
	if ((return_value = ft_cub3d_recursive_wall(test_map, \
							map_params->starting_pos_x + 1, \
							map_params->starting_pos_y + 1)) != SUCCESS)
		return_value = MAP_IS_OPEN;
	i = -1;
	while (test_map[++i])
		free(test_map[i]);
	free(test_map);
	return (return_value);
}

void						ft_cub3d_print_map(char **map)
{
	ssize_t	i;

	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}

int							ft_cub3d_recursive_wall(char **test_map, \
													size_t x, \
													size_t y)
{
	int	return_value;

	return_value = 0;
	if ((test_map[y][x] == 'v') || (test_map[y][x] == '1'))
		return (0);
	else if (test_map[y][x] == 'X')
		return (1);
	if ((ft_strlen(test_map[y - 1]) <= x) || (ft_strlen(test_map[y + 1]) <= x))
		return (1);
	else
	{
		test_map[y][x] = 'v';
		return_value += ft_cub3d_recursive_wall(test_map, x, y + 1);
		return_value += ft_cub3d_recursive_wall(test_map, x + 1, y);
		return_value += ft_cub3d_recursive_wall(test_map, x, y - 1);
		return_value += ft_cub3d_recursive_wall(test_map, x - 1, y);
	}
	return (return_value);
}
