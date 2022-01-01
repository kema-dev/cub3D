/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:05:16 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/11 11:15:57 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int							ft_cub3d_sprite_count(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map_params->map[++i])
	{
		j = -1;
		while (data->map_params->map[i][++j])
		{
			if (data->map_params->map[i][j] == '2')
			{
				data->sprite->count++;
			}
		}
	}
	return (i);
}

void						ft_cub3d_init_sprites(t_data *data)
{
	if (!(data->sprite = ft_calloc(1, sizeof(t_sprite))))
		exit(ft_cub3d_print_errno(MALLOC_FAIL));
	ft_cub3d_sprite_count(data);
	if (!(data->sprite->order = ft_calloc(data->sprite->count, sizeof(int))))
		exit(ft_cub3d_print_errno(MALLOC_FAIL));
	if (!(data->sprite->dist = ft_calloc(data->sprite->count, sizeof(double))))
		exit(ft_cub3d_print_errno(MALLOC_FAIL));
	if (!(data->sprite->coord = ft_calloc(data->sprite->count, \
										sizeof(t_coord))))
		exit(ft_cub3d_print_errno(MALLOC_FAIL));
	if (!(data->sprite->z_buffer = ft_calloc(data->map_params->res_width, \
											sizeof(double))))
		exit(ft_cub3d_print_errno(MALLOC_FAIL));
	ft_cub3d_fill_sprites(data);
}

void						ft_cub3d_fill_sprites(t_data *data)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	k;

	i = 0;
	k = 0;
	while (data->map_params->map[++i])
	{
		j = -1;
		while (data->map_params->map[i][++j])
		{
			if (data->map_params->map[i][j] == '2')
			{
				data->sprite->coord[k].y = (double)i + 0.5;
				data->sprite->coord[k].x = (double)j + 0.5;
				k++;
			}
		}
	}
}

void						ft_cub3d_swap_array(t_data *data, ssize_t i)
{
	int		tmp_int;
	double	tmp_double;
	t_coord	tmp_coord;

	tmp_double = data->sprite->dist[i];
	data->sprite->dist[i] = data->sprite->dist[i + 1];
	data->sprite->dist[i + 1] = tmp_double;
	tmp_int = data->sprite->order[i];
	data->sprite->order[i] = data->sprite->order[i + 1];
	data->sprite->order[i + 1] = tmp_int;
	tmp_coord = data->sprite->coord[i];
	data->sprite->coord[i] = data->sprite->coord[i + 1];
	data->sprite->coord[i + 1] = tmp_coord;
}

void						ft_cub3d_sort_sprites(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->sprite->count)
	{
		data->sprite->order[i] = i;
		data->sprite->dist[i] = ((data->pos_x - data->sprite->coord[i].x) \
			* (data->pos_x - data->sprite->coord[i].x) + (data->pos_y \
			- data->sprite->coord[i].y) * (data->pos_y - \
			data->sprite->coord[i].y));
	}
	i = -1;
	while (++i < data->sprite->count - 1)
	{
		if (data->sprite->dist[i] < data->sprite->dist[i + 1])
		{
			ft_cub3d_swap_array(data, i);
			i--;
		}
	}
}
