/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_create_bmp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:01:34 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/11 11:15:39 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void						ft_cub3d_create_bmp_2(t_data *data, int fd)
{
	int		tmp;
	ssize_t	i;
	ssize_t	x;
	ssize_t	y;

	i = -1;
	tmp = 0;
	while (++i < 28)
		write(fd, &tmp, 1);
	y = data->map_params->res_height;
	while (--y >= 0)
	{
		x = 0;
		while (x < (ssize_t)data->map_params->res_width)
		{
			write(fd, &data->addr[y * data->line_length \
				+ x * (data->bits_per_pixel / 8)], 4);
			x++;
		}
	}
}

int							ft_cub3d_create_bmp(t_data *data, int fd)
{
	int		tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * data->map_params->res_width \
					* data->map_params->res_height;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 4);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &data->map_params->res_width, 4);
	write(fd, &data->map_params->res_height, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	tmp = data->bits_per_pixel;
	write(fd, &tmp, 2);
	ft_cub3d_create_bmp_2(data, fd);
	return (SUCCESS);
}
