/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:16:02 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 11:27:08 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*space_string(size_t len, t_param *world)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		error_exit("Space string malloc error ", world, NULL, -1);
	while (i < len)
		res[i++] = 'v';
	res[i] = '\0';
	return (res);
}
