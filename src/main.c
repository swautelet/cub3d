/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:19:31 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/08 00:23:25 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_mapD	map;
	t_param	*world;

	if (argc != 2)
		error_exit("[USAGE] ./cub3D <map.cub> ");
	map = cub_file_check_and_fill(argv[1]);
	// int	i = 0;
	// while (map.map[i])
	// 	printf("%s\n", map.map[i++]);
	world = malloc(sizeof(t_param));
	if (world)
	{
		world->map_data = &map;
		world->p_x_pos = (map.pos_x * SIZE) + SIZE / 2;
		world->p_y_pos = (map.pos_y * SIZE) + SIZE / 2;
		world->p_orient = 0;
		world->map = map.map;
		world->map_height = map.map_height;
		world->map_width = map.map_length;
		world->screen_height = SCREEN_HEIGHT;
		world->screen_width = SCREEN_WIDTH;
		world->floor_color = map.floor;
		world->ceiling_color = map.ceiling;
		world->wall_color = create_trgb(0, 0, 0, 255);
		init_window(world);
		free (world);
	}
	return (0);
}
