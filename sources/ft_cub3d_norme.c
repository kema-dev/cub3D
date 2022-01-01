/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_norme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:49:10 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/25 16:13:02 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void						ft_cub3d_get_resolution_2(t_map_params *map_params,\
														char **str)
{
	while ((*str[0] >= '0') && (*str[0] <= '9'))
		(*str)++;
	if (map_params->res_width > MAX_RES_WIDTH)
		map_params->res_width = MAX_RES_WIDTH;
	if (map_params->res_height > MAX_RES_HEIGHT)
		map_params->res_height = MAX_RES_HEIGHT;
	if (map_params->res_width < MIN_RES_WIDTH)
	{
		map_params->res_width = MIN_RES_WIDTH;
		printf("ADAPTED RESOLUTION WIDTH TO %d\n", MIN_RES_WIDTH);
	}
	if (map_params->res_height < MIN_RES_HEIGHT)
	{
		map_params->res_height = MIN_RES_HEIGHT;
		printf("ADAPTED RESOLUTION HEIGHT TO %d\n", MIN_RES_HEIGHT);
	}
}

int							ft_cub3d_get_texture_2(char *path, \
												char *dest, \
												t_map_params *map_params)
{
	if ((strncmp(dest, "NO", 2) == 0) && (!map_params->north_text))
		map_params->north_text = path;
	else if ((strncmp(dest, "SO", 2) == 0) && (!map_params->south_text))
		map_params->south_text = path;
	else if ((strncmp(dest, "WE", 2) == 0) && (!map_params->west_text))
		map_params->west_text = path;
	else if ((strncmp(dest, "EA", 2) == 0) && (!map_params->east_text))
		map_params->east_text = path;
	else if ((strncmp(dest, "S", 1) == 0) && (!map_params->sprite_text))
		map_params->sprite_text = path;
	else
		exit(ft_cub3d_print_errno(DOUBLE_DEF));
	return (SUCCESS);
}

int							ft_cub3d_get_plane_2(char **str, \
												int *r, \
												int *g, \
												int *b)
{
	ft_cub3d_go_next_word(str, ' ', '\n');
	if (((*r = ft_atoi(*str)) < 0) || ((*r == 0) && ((*str[0] != '0'))))
		exit(ft_cub3d_print_errno(MAP_INVALID_COLOR));
	ft_cub3d_pass_digit(str);
	if (*str[0] != ',')
		exit(ft_cub3d_print_errno(MAP_INVALID_COLOR));
	else
		(*str)++;
	if (((*g = ft_atoi(*str)) < 0) || ((*g == 0) && ((*str[0] != '0'))))
		exit(ft_cub3d_print_errno(MAP_INVALID_COLOR));
	ft_cub3d_pass_digit(str);
	if (*str[0] != ',')
		exit(ft_cub3d_print_errno(MAP_INVALID_COLOR));
	else
		(*str)++;
	if (((*b = ft_atoi(*str)) < 0) || ((*b == 0) && ((*str[0] != '0'))))
		exit(ft_cub3d_print_errno(MAP_INVALID_COLOR));
	if ((*r > 255) || (*g > 255) || (*b > 255))
		exit(ft_cub3d_print_errno(MAP_INVALID_COLOR));
	return (SUCCESS);
}

int							ft_cub3d_get_plane_3(char **str)
{
	while ((*str[0]) && (*str[0] != '\n'))
	{
		if (*str[0] != ' ')
			exit(ft_cub3d_print_errno(MAP_INVALID_COLOR));
		(*str)++;
	}
	return (SUCCESS);
}

int							ft_cub3d_res_atoi(const char *nptr)
{
	unsigned int	n;
	int				neg;

	neg = 1;
	if (!nptr)
		return (0);
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	n = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (n > n * 10 + *nptr - '0')
			return (-1);
		n = n * 10 + *nptr - '0';
		nptr++;
	}
	n *= neg;
	return (n);
}
