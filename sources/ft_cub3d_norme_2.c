/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_norme_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:19:58 by jjourdan          #+#    #+#             */
/*   Updated: 2021/03/22 10:22:48 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t						ft_cub3d_nb_strs_2(char const *s, size_t i, char c)
{
	while (s[i] == c)
		i++;
	if (s[i])
		exit(ft_cub3d_print_errno(MAP_INVALID_CHAR));
	return (i);
}
