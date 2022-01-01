/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_s2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourdan <jjourdan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 15:33:41 by jjourdan          #+#    #+#             */
/*   Updated: 2021/02/05 15:34:14 by jjourdan         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free_s2(char *s1, char *s2)
{
	size_t	tot_len;
	char	*out;

	tot_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(out = ft_calloc(sizeof(char), (tot_len + 1))))
		return (NULL);
	ft_strcat(out, (char *)s1);
	ft_strcat(out, (char *)s2);
	free(s2);
	return (out);
}
