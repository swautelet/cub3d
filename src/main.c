/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:19:31 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/02 13:21:24 by simonwautel      ###   ########.fr       */
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
	// Output test
	// printf("Output test in main\n");
	// printf("NO : %s\n", map.no);
	// printf("SO : %s\n", map.so);
	// printf("WE : %s\n", map.we);
	// printf("EA : %s\n", map.ea);
	// printf("F : %d\n", map.floor);
	// printf("C : %d\n", map.ceiling);
	// printf("Map max len : %d\n", map.map_len);
	// printf("Map max hight : %d\n", map.map_hight);
	// int	i = 0;
	// while (map.map[i])
	// 	printf("%s\n", map.map[i++]);
	world = malloc(sizeof(t_param));
	if (world)
	{
		world->p_x_pos = 25;
		world->p_y_pos = 3;
		world->p_orient = 0;
		world->map = map.map;
		world->map_height = map.map_hight;
		world->map_width = map.map_len;
		world->screen_height = 900;
		world->screen_width = 600;
		world->floor_color = map.floor;
		world->ceiling_color = map.ceiling;
		init_window(world);
		free (world);
	}
	return (0);
}
