/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:49:26 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/16 15:28:29 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int						ft_cub3d_move_vert(t_data *data)
{
	char	tile;

	if (data->forward == true)
	{
		tile = data->map_params->map[(int)floor(data->pos_y + data->dir_y \
					* data->move_speed * 1.5)][(int)floor(data->pos_x \
					+ data->dir_x * data->move_speed * 1.5)];
		if ((tile == '0') || (tile == data->map_params->orientation))
		{
			data->pos_y += data->dir_y * data->move_speed;
			data->pos_x += data->dir_x * data->move_speed;
		}
	}
	else if (data->backward == true)
	{
		tile = data->map_params->map[(int)floor(data->pos_y - data->dir_y \
					* data->move_speed * 1.5)][(int)floor(data->pos_x \
					- data->dir_x * data->move_speed * 1.5)];
		if ((tile == '0') || (tile == data->map_params->orientation))
		{
			data->pos_y -= data->dir_y * data->move_speed;
			data->pos_x -= data->dir_x * data->move_speed;
		}
	}
	return (SUCCESS);
}

int						ft_cub3d_move_horiz(t_data *data)
{
	char	tile;

	if (data->left == true)
	{
		tile = data->map_params->map[(int)floor(data->pos_y - data->dir_x \
					* data->move_speed * 1.5)][(int)floor(data->pos_x \
					+ data->dir_y * data->move_speed * 1.5)];
		if ((tile == '0') || (tile == data->map_params->orientation))
		{
			data->pos_y -= data->dir_x * data->move_speed;
			data->pos_x += data->dir_y * data->move_speed;
		}
	}
	else if (data->right == true)
	{
		tile = data->map_params->map[(int)floor(data->pos_y + data->dir_x \
					* data->move_speed * 1.5)][(int)floor(data->pos_x \
					- data->dir_y * data->move_speed * 1.5)];
		if ((tile == '0') || (tile == data->map_params->orientation))
		{
			data->pos_y += data->dir_x * data->move_speed;
			data->pos_x -= data->dir_y * data->move_speed;
		}
	}
	return (SUCCESS);
}

void					ft_cub3d_move_rotate_2(t_data *data, \
											double prev_dir_x, \
											double prev_plane_x)
{
	if (data->rot_right == true)
	{
		data->dir_x = data->dir_x * cos(data->rot_speed) \
					- data->dir_y * sin(data->rot_speed);
		data->dir_y = prev_dir_x * sin(data->rot_speed) \
					+ data->dir_y * cos(data->rot_speed);
		data->plane_x = data->plane_x * cos(data->rot_speed) \
					- data->plane_y * sin(data->rot_speed);
		data->plane_y = prev_plane_x * sin(data->rot_speed) \
					+ data->plane_y * cos(data->rot_speed);
	}
}

int						ft_cub3d_move_rotate(t_data *data)
{
	double	prev_dir_x;
	double	prev_plane_x;

	prev_dir_x = data->dir_x;
	prev_plane_x = data->plane_x;
	if (data->rot_left == true)
	{
		data->dir_x = data->dir_x * cos(-data->rot_speed) \
					- data->dir_y * sin(-data->rot_speed);
		data->dir_y = prev_dir_x * sin(-data->rot_speed) \
					+ data->dir_y * cos(-data->rot_speed);
		data->plane_x = data->plane_x * cos(-data->rot_speed) \
					- data->plane_y * sin(-data->rot_speed);
		data->plane_y = prev_plane_x * sin(-data->rot_speed) \
					+ data->plane_y * cos(-data->rot_speed);
	}
	else
		ft_cub3d_move_rotate_2(data, prev_dir_x, prev_plane_x);
	return (SUCCESS);
}
