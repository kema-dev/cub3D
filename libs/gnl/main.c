/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:28:58 by jjourdan          #+#    #+#             */
/*   Updated: 2021/01/26 10:41:43 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	**line;
	int		fd;
	size_t	i;
	size_t	nb_itt;

	i = 0;
	nb_itt = 20;
	fd = open("./file", O_RDONLY);
	line = malloc(sizeof(char **) * nb_itt);
	while (i < nb_itt)
	{
		printf("out=%d ", get_next_line(fd, line));
		printf("line=%s\n", *line);
		printf("line=%ld\n", i + 1);
		free(*line);
		line++;
		i++;
	}
	line -= i;
	free(line);
}
