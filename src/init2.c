/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:53:50 by swautele          #+#    #+#             */
/*   Updated: 2022/06/18 16:07:51 by swautele         ###   ########.fr       */
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
	fd = open("texture/door.xpm", O_RDONLY);
	if (fd == -1)
		error_exit("Invalid texture path", world, NULL, -1);
	close(fd);
	fd = open("texture/keyblade.xpm", O_RDONLY);
	if (fd == -1)
		error_exit("Invalid texture path", world, NULL, -1);
	close(fd);
	checkpath_texture(world, fd);
}
