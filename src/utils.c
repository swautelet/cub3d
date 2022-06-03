/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:33:12 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/03 16:04:13 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	to_hex_int(const char *str)
{
	char	**split;
	int	r;
	int g;
	int b;

	split = ft_split(str, ',');
	if (!(ft_isstrdigit(split[0]) && ft_isstrdigit(split[1]) && ft_isstrdigit(split[2])))
		error_exit("Corrupted .cub file ");
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	return (0 << 24 | r << 16 | g << 8 | b);
}

size_t	len_array_2d(char **split)
{
	size_t	res;

	res = 0;
	while (split[res])
		res++;
	return (res);
}

void	exit_cub3d(t_param *world)
{
	mlx_destroy_image(world->video, world->img->img);
	mlx_destroy_window(world->video, world->window);
	free(world->img);
	free(world);
	exit (0);
}
