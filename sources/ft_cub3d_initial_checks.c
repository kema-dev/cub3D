/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_initial_checks.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 12:23:13 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/25 15:11:23 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3d_check_arg(int argc,\
												char **argv, \
												bool *save)
{
	if ((argc <= 1) || (argc >= 4))
		exit(ft_cub3d_print_errno(INVALID_ARG_NUM));
	if (argv[2])
	{
		if (ft_strncmp(argv[2], "--save", 7) != SUCCESS)
			exit(ft_cub3d_print_errno(INVALID_ARG));
		else
			*save = true;
	}
	if (ft_strlen(argv[1]) <= 4)
		exit(ft_cub3d_print_errno(MAP_INVALID_EXT));
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != SUCCESS)
		exit(ft_cub3d_print_errno(MAP_INVALID_EXT));
	return (SUCCESS);
}

int							ft_cub3d_check_map_is_dir(char *map_path)
{
	int		fd;

	if ((fd = open(map_path, O_DIRECTORY)) >= 0)
	{
		close(fd);
		exit(ft_cub3d_print_errno(MAP_IS_DIR));
	}
	else
		return (SUCCESS);
}

int							ft_cub3d_check_map(char *map_path, \
												t_map_params *map_params, \
												char *map_lines)
{
	int		fd;
	int		return_value;
	char	*buf;

	return_value = 0;
	if (ft_cub3d_check_map_is_dir(map_path) != SUCCESS)
		exit(ft_cub3d_print_errno(MAP_IS_DIR));
	else if ((fd = open(map_path, O_RDONLY)) < 0)
		exit(ft_cub3d_print_errno(MAP_INVALID_READ));
	while ((return_value = get_next_line(fd, &buf)) > 0)
	{
		map_lines = ft_strjoin_free_s1(map_lines, buf);
		map_lines = ft_strjoin_free_s1(map_lines, "\n");
		free(buf);
	}
	map_lines = ft_strjoin_free_s1(map_lines, buf);
	free(buf);
	if (return_value < 0)
		exit(ft_cub3d_print_errno(MAP_INVALID_READ));
	close(fd);
	if ((return_value = ft_cub3d_get_map_params(map_params, \
												map_lines)) != SUCCESS)
		exit(ft_cub3d_print_errno(return_value));
	return (SUCCESS);
}

int							ft_cub3d_start_is_charset(t_map_params \
												*map_params, \
												ssize_t i, \
												ssize_t j, \
												char *charset)
{
	ssize_t	k;

	k = -1;
	while (charset[++k])
	{
		if (map_params->map[i][j] == charset[k])
		{
			if (map_params->orientation == 0)
			{
				map_params->orientation = charset[k];
				map_params->starting_pos_x = j;
				map_params->starting_pos_y = i;
			}
			else
				return (MAP_INVALID_POS);
		}
	}
	return (SUCCESS);
}
