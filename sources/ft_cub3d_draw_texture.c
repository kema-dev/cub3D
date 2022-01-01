/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_draw_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:04:14 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/11 14:49:44 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void						ft_cub3d_text_init(t_data *data)
{
	if (data->side == 0 && data->ray_dir_y < 0)
		data->tex_val.dir = 0;
	else if (data->side == 0)
		data->tex_val.dir = 1;
	if (data->side == 1 && data->ray_dir_x < 0)
		data->tex_val.dir = 3;
	else if (data->side == 1)
		data->tex_val.dir = 2;
	if (data->side == 0)
		data->tex_val.wall_x = data->pos_x + data->perp_wall_dist \
							* data->ray_dir_x;
	else
		data->tex_val.wall_x = data->pos_y + data->perp_wall_dist \
							* data->ray_dir_y;
	data->tex_val.wall_x -= floor((data->tex_val.wall_x));
}

void						ft_cub3d_put_texture(t_data *data, \
										int x, ssize_t *y)
{
	*y = data->draw_start;
	ft_cub3d_text_init(data);
	data->tex_val.step = (double)data->texture[data->tex_val.dir].y \
		/ data->line_height;
	data->tex_val.x = (int)(data->tex_val.wall_x * \
			(double)data->texture[data->tex_val.dir].x);
	if (data->side == 0)
		data->tex_val.y = data->texture[data->tex_val.dir].x - \
			data->tex_val.y + 1;
	else
		data->tex_val.x = data->texture[data->tex_val.dir].x - \
			data->tex_val.x + 1;
	data->tex_val.pos = (data->draw_start - data->map_params->res_height / 2 +\
			data->line_height / 2) * data->tex_val.step;
	while (++*y <= data->draw_end)
	{
		data->tex_val.y = (int)data->tex_val.pos &\
			(data->texture[data->tex_val.dir].y - 1);
		data->tex_val.pos += data->tex_val.step;
		if (*y < (ssize_t)data->map_params->res_height && \
				x < data->map_params->res_width)
			ft_cub3d_swap_addr(data, x, y);
	}
}

void						ft_cub3d_swap_addr(t_data *data, int x, ssize_t *y)
{
	data->addr[*y * data->line_length + x *\
			(data->bits_per_pixel) / 8] =
		data->texture[data->tex_val.dir].addr[data->tex_val.y *\
		data->texture[data->tex_val.dir].size_line + data->tex_val.x *\
		(data->texture[data->tex_val.dir].bits_per_pixel) / 8];
	data->addr[*y * data->line_length + x *\
			(data->bits_per_pixel) / 8 + 1] =
		data->texture[data->tex_val.dir].addr[data->tex_val.y *\
		data->texture[data->tex_val.dir].size_line + data->tex_val.x *\
		(data->texture[data->tex_val.dir].bits_per_pixel) / 8 + 1];
	data->addr[*y * data->line_length + x *\
			(data->bits_per_pixel) / 8 + 2] =
		data->texture[data->tex_val.dir].addr[data->tex_val.y *\
		data->texture[data->tex_val.dir].size_line + data->tex_val.x *\
		(data->texture[data->tex_val.dir].bits_per_pixel) / 8 + 2];
}
