/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_print_sprites.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:44:15 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/11 11:24:30 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void						ft_cub3d_set_sprite_addr(t_data *data, \
													ssize_t y, \
													int tex_x, \
													int stripe)
{
	int d;
	int	tex_y;

	d = y * 256 - data->map_params->res_height * 128 \
		+ data->sprite->height * 128;
	tex_y = ((d * data->texture[4].y) / data->sprite->height) / 256;
	data->addr[y * data->line_length + stripe * data->bits_per_pixel / 8] = \
		data->texture[4].addr[tex_y * data->texture[4].size_line + tex_x \
		* data->texture[4].bits_per_pixel / 8];
	data->addr[y * data->line_length + stripe * data->bits_per_pixel / 8 \
		+ 1] = data->texture[4].addr[tex_y \
		* data->texture[4].size_line + tex_x \
		* data->texture[4].bits_per_pixel / 8 + 1];
	data->addr[y * data->line_length + stripe \
		* data->bits_per_pixel / 8 + 2] = data->texture[4].addr[tex_y \
		* data->texture[4].size_line + tex_x \
		* data->texture[4].bits_per_pixel / 8 + 2];
}

void						ft_cub3d_put_sprites_2(t_data *data, \
													int tex_x, \
													int stripe)
{
	ssize_t	y;
	int		d;
	int		tex_y;

	y = data->sprite->start_y;
	while (y < data->sprite->end_y)
	{
		d = y * 256 - data->map_params->res_height * 128 \
			+ data->sprite->height * 128;
		tex_y = ((d * data->texture[4].y) / data->sprite->height) / 256;
		if (data->texture[4].addr[tex_y * data->texture[4].size_line \
				+ tex_x * data->texture[4].bits_per_pixel / 8])
			ft_cub3d_set_sprite_addr(data, y, tex_x, stripe);
		y++;
	}
}

void						ft_cub3d_put_sprites(t_data *data)
{
	int		stripe;
	int		tex_x;

	stripe = data->sprite->start_x;
	while (stripe < (int)data->sprite->end_x)
	{
		tex_x = (int)(256 * (stripe - (-data->sprite->width / 2 \
			+ data->sprite->screen)) * data->texture[4].x \
			/ data->sprite->width) / 256;
		if ((data->sprite->trans_y > 0) && (stripe >= 0) \
			&& (stripe < (int)data->map_params->res_width) \
			&& (data->sprite->trans_y < data->sprite->z_buffer[stripe]))
		{
			ft_cub3d_put_sprites_2(data, tex_x, stripe);
		}
		stripe++;
	}
}

void						ft_cub3d_project_sprites_2(t_data *data)
{
	data->sprite->height = abs((int)(data->map_params->res_height \
						/ data->sprite->trans_y));
	data->sprite->start_y = -data->sprite->height / 2 \
						+ data->map_params->res_height / 2;
	if (data->sprite->start_y < 0)
		data->sprite->start_y = 0;
	data->sprite->end_y = data->sprite->height / 2 \
						+ data->map_params->res_height / 2;
	if (data->sprite->end_y > (int)data->map_params->res_height)
		data->sprite->end_y = (int)data->map_params->res_height;
	data->sprite->width = abs((int)(data->map_params->res_height \
						/ data->sprite->trans_y));
	data->sprite->start_x = -data->sprite->width \
						/ 2 + data->sprite->screen;
	if (data->sprite->start_x < 0)
		data->sprite->start_x = 0;
	data->sprite->end_x = data->sprite->width / 2 + data->sprite->screen;
	if (data->sprite->end_x > (int)data->map_params->res_width)
		data->sprite->end_x = (int)data->map_params->res_width;
}

void						ft_cub3d_project_sprites(t_data *data)
{
	ssize_t	i;

	i = -1;
	while (++i < (ssize_t)data->sprite->count)
	{
		data->sprite->x = data->sprite->coord[i].x - data->pos_x;
		data->sprite->y = data->sprite->coord[i].y - data->pos_y;
		data->sprite->inv_det = 1 / (data->plane_x * data->dir_y \
							- data->dir_x * data->plane_y);
		data->sprite->trans_x = data->sprite->inv_det * \
							(data->dir_y * data->sprite->x \
							- data->dir_x * data->sprite->y);
		data->sprite->trans_y = data->sprite->inv_det * \
							(-data->plane_y * data->sprite->x \
							+ data->plane_x * data->sprite->y);
		data->sprite->screen = data->map_params->res_width / 2 \
							* (1 + data->sprite->trans_x \
							/ data->sprite->trans_y);
		ft_cub3d_project_sprites_2(data);
		ft_cub3d_put_sprites(data);
	}
}
