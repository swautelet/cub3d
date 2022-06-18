/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:53:50 by swautele          #+#    #+#             */
/*   Updated: 2022/06/18 14:44:32 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

static void	checkpath_texture(t_param *world, int fd)
{
	fd = open(world->ea, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid texture path", world, NULL, -1);
	close(fd);
	fd = open(world->ea, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid texture path", world, NULL, -1);
	close(fd);
	fd = open(world->ea, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid texture path", world, NULL, -1);
	close(fd);
	fd = open(world->ea, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid texture path", world, NULL, -1);
	close(fd);
	fd = open(world->ea, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid texture path", world, NULL, -1);
	close(fd);
	fd = open(world->ea, O_RDONLY);
	if (fd == -1)
		error_exit("Invalid texture path", world, NULL, -1);
	close(fd);
}

void	init_second_part(t_param *world)
{
	int	fd;

	fd = -1;
	if (world->map_width > world->map_height)
		world->square_length = (world->nb_ray / 3) / world->map_width;
	else
		world->square_length = (SCREEN_HEIGHT / 3) / world->map_height;
	world->player_size = world->square_length / 3;
	checkpath_texture(world, fd);
}
