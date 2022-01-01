/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:32:58 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/17 13:27:32 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					main(int argc, char **argv)
{
	bool			save;
	int				return_value;
	char			*map_lines;
	t_map_params	*map_params;

	map_lines = NULL;
	save = false;
	if (!(map_params = ft_calloc(sizeof(t_map_params), 1)))
		exit(ft_cub3d_print_errno(MALLOC_FAIL));
	if ((return_value = ft_cub3d_check_arg(argc, argv, &save)) != SUCCESS)
		exit(ft_cub3d_print_errno(return_value));
	if ((return_value = ft_cub3d_check_map(argv[1], map_params, \
											map_lines)) != SUCCESS)
		exit(ft_cub3d_print_errno(return_value));
	if (save == true)
	{
		if ((return_value = (ft_cub3d_save_file(map_params)) != SUCCESS))
			exit(ft_cub3d_print_errno(return_value));
	}
	else
	{
		if ((return_value = (ft_cub3d_launch_game(map_params)) != SUCCESS))
			exit(ft_cub3d_print_errno(return_value));
	}
	exit(SUCCESS);
}
