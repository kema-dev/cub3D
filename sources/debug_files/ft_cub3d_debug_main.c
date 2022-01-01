/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_debug_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:58:19 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/12 16:34:00 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** int					main(int argc, char **argv)
** {
** 	int				save;
** 	int				return_value;
** 	char			*map_lines;
** 	t_map_params	*map_params;
**
** 	map_lines = NULL;
** 	if (!(map_params = ft_calloc(sizeof(t_map_params), 1)))
** 		return (MALLOC_FAIL);
** 	if ((return_value = ft_cub3d_check_arg(argc, argv, &save)) != SUCCESS)
** 		return (ft_cub3d_print_errno(return_value));
** 	if ((return_value = ft_cub3d_check_map(argv[1], map_params, \
** 											map_lines)) != SUCCESS)
** 		return (ft_cub3d_print_errno(return_value));
** 	return_value = ft_cub3d_exit_exec(return_value, map_params);
** 	return (return_value);
** }
*/

int				main(void)
{
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "Leche moi le cub");
	mlx_hook(vars.mlx_win, 2, 1L << 0, ft_cub3d_check_key_event, &vars);
	mlx_hook(vars.mlx_win, 17, 10001, ft_cub3d_kill_all, &vars);
	mlx_loop(vars.mlx);
	return (SUCCESS);
}
