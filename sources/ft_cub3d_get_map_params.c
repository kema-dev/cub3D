/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_get_map_params.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:43:29 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/25 16:12:02 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3d_check_init_params(t_map_params *map_params)
{
	if ((!map_params->res_width) || (!map_params->res_height) \
				|| (!map_params->north_text) || (!map_params->south_text) \
				|| (!map_params->east_text) || (!map_params->west_text) \
				|| (!map_params->sprite_text) || (!map_params->field) \
				|| (!map_params->orientation) || (!map_params->starting_pos_x) \
				|| (!map_params->starting_pos_y))
		exit(ft_cub3d_print_errno(MISSING_PARAM));
	return (SUCCESS);
}

int							ft_cub3d_get_map_params(t_map_params *map_params, \
									char *map_lines)
{
	char	*tmp;
	int		return_value;

	tmp = map_lines;
	map_params->floor_color = -1;
	map_params->ceiling_color = -1;
	while ((return_value = ft_cub3d_get_next_param(&tmp, map_params)) \
															== SUCCESS)
		;
	if ((return_value != SUCCESS) && (return_value != PASS))
		exit(ft_cub3d_print_errno(return_value));
	free(map_lines);
	if ((return_value = ft_cub3d_2d_map(map_params)) != SUCCESS)
		exit(ft_cub3d_print_errno(return_value));
	if ((return_value = ft_cub3d_check_init_params(map_params)) != SUCCESS)
		exit(ft_cub3d_print_errno(return_value));
	return (SUCCESS);
}

int							ft_cub3d_last_checks(char **tmp, \
												t_map_params *map_params)
{
	if ((map_params->ceiling_color == -1) || (map_params->floor_color == -1))
		exit(ft_cub3d_print_errno(MISSING_PARAM));
	ft_cub3d_get_field(tmp, map_params);
	if (*tmp[0] != 0)
		exit(ft_cub3d_print_errno(MAP_INVALID_CONFIG));
	else
		return (PASS);
}

int							ft_cub3d_get_next_param(char **tmp, \
									t_map_params *map_params)
{
	while (*tmp[0] == '\n')
		(*tmp)++;
	if (*tmp[0] == 'R')
	{
		if (ft_cub3d_get_resolution(tmp, map_params))
			exit(ft_cub3d_print_errno(MAP_INVALID_RES));
	}
	else if ((strncmp(*tmp, "NO ", 3) == 0) || (strncmp(*tmp, "SO ", 3) == 0) \
		|| (strncmp(*tmp, "WE ", 3) == 0) || (strncmp(*tmp, "EA ", 3) == 0) \
		|| (strncmp(*tmp, "S ", 2) == 0))
	{
		if (ft_cub3d_get_texture(tmp, map_params))
			exit(ft_cub3d_print_errno(TEXT_FAILURE));
	}
	else if ((strncmp(*tmp, "F ", 2) == 0) || (strncmp(*tmp, "C ", 2) == 0))
	{
		if (ft_cub3d_get_plane(tmp, map_params))
			exit(ft_cub3d_print_errno(MAP_INVALID_COLOR));
	}
	else
	{
		return (ft_cub3d_last_checks(tmp, map_params));
	}
	return (SUCCESS);
}
