/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_cast_rays.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:02:33 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/16 13:35:25 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void							ft_cub3d_raycast_param(t_data *data)
{
	data->move_speed = 0.15;
	data->rot_speed = 0.05;
	data->forward = 0;
	data->backward = 0;
	data->right = 0;
	data->left = 0;
	data->rot_left = 0;
	data->rot_right = 0;
	data->pos_x = (double)data->map_params->starting_pos_x + 0.5;
	data->pos_y = (double)data->map_params->starting_pos_y + 0.5;
	data->dir_x = 0;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0;
	data->frame_uni = 0;
}

void							ft_cub3d_raycast_init(t_data *data, ssize_t x)
{
	data->camera_x = 2 * x / (double)data->map_params->res_width - 1;
	data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x;
	data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x;
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	data->delta_dist_x = fabs(1 / data->ray_dir_x);
	data->delta_dist_y = fabs(1 / data->ray_dir_y);
	data->hit = 0;
}

void							ft_cub3d_raycast_side(t_data *data)
{
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y) \
							* data->delta_dist_y;
	}
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x) \
							* data->delta_dist_x;
	}
}

void							ft_cub3d_raycast_orientation(t_data *data)
{
	if (data->map_params->orientation == 'N')
	{
		data->dir_y = -1;
		data->plane_x = 0.60;
	}
	else if (data->map_params->orientation == 'S')
	{
		data->dir_y = 1;
		data->plane_x = -0.60;
	}
	else if (data->map_params->orientation == 'W')
	{
		data->dir_x = -1;
		data->plane_y = -0.60;
	}
	else if (data->map_params->orientation == 'E')
	{
		data->dir_x = 1;
		data->plane_y = 0.60;
	}
}

int								ft_cub3d_cast_rays(t_data *data)
{
	ssize_t	x;

	x = -1;
	while (++x < (ssize_t)data->map_params->res_width)
	{
		ft_cub3d_raycast_init(data, x);
		ft_cub3d_raycast_side(data);
		ft_cub3d_hitbox(data);
		ft_cub3d_draw_ray(data);
		ft_cub3d_pixel_creation(data, x);
	}
	return (SUCCESS);
}
