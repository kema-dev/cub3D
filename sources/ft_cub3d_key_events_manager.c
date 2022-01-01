/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_key_events_manager.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:04:01 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/16 13:21:03 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_cub3d_release(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->forward = false;
	else if (keycode == A_KEY)
		data->left = false;
	else if (keycode == S_KEY)
		data->backward = false;
	else if (keycode == D_KEY)
		data->right = false;
	else if (keycode == LEFT_ARROW_KEY)
		data->rot_left = false;
	else if (keycode == RIGHT_ARROW_KEY)
		data->rot_right = false;
	return (SUCCESS);
}

void		ft_cub3d_reset_input(t_data *data)
{
	data->forward = false;
	data->left = false;
	data->backward = false;
	data->right = false;
	data->rot_left = false;
	data->rot_right = false;
	data->other = false;
}

void		ft_cub3d_invalid_input(int keycode, \
							t_data *data)
{
	data->other = true;
	printf("keycode %d does nothing!\n", keycode);
}

int			ft_cub3d_check_key_event(int keycode, \
								t_data *data)
{
	if (keycode == ESC_KEY)
		ft_cub3d_exit();
	else if (keycode == W_KEY)
		data->forward = true;
	else if (keycode == A_KEY)
		data->left = true;
	else if (keycode == S_KEY)
		data->backward = true;
	else if (keycode == D_KEY)
		data->right = true;
	else if (keycode == LEFT_ARROW_KEY)
		data->rot_left = true;
	else if (keycode == RIGHT_ARROW_KEY)
		data->rot_right = true;
	else
		ft_cub3d_invalid_input(keycode, data);
	return (SUCCESS);
}
