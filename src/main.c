/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:02:55 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 14:47:39 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	debug(t_param *world)
// {
// 	int	i;

// 	i = 0;
// 	printf(" ===== START DEBUG ===== \n");
// 	while (world->map[i])
// 		printf("%s\n", world->map[i++]);
// 	printf("-----------------------------\n");
// 	printf("Player px x pos : %f\n", world->px_x_pos);
// 	printf("Player px y pos : %f\n", world->px_y_pos);
// 	printf("Player map x pos : %d\n", world->map_x_pos);
// 	printf("Player map y pos : %d\n", world->map_y_pos);
// 	printf("Player orientation : %d\n", world->orient);
// 	printf("-----------------------------\n");
// 	printf("Map height : %d\n", world->map_height);
// 	printf("Map width : %d\n", world->map_width);
// 	printf("-----------------------------\n");
// 	printf("Map start : %d\n", world->map_start);
// 	printf("-----------------------------\n");
// 	printf("Map .cub path : %s\n", world->path);
// 	printf("Map NO path : %s\n", world->no);
// 	printf("Map SO path : %s\n", world->so);
// 	printf("Map WE path : %s\n", world->we);
// 	printf("Map EA path : %s\n", world->ea);
// 	printf("-----------------------------\n");
// 	printf("Map floor color : %d\n", world->floor_color);
// 	printf("Map ceiling color : %d\n", world->ceiling_color);
// 	printf(" ===== END DEBUG ===== \n");
// }

int	main(int argc, char **argv)
{
	t_param	*world;
	char	*strerr;

	world = NULL;
	if (argc != 2)
	{
		strerr = "Error\nInvalid number of  arguments\n";
		write (2, strerr, ft_strlen(strerr));
		exit(1);
	}
	world = malloc(sizeof(t_param));
	if (world)
	{
		init_world(world);
		cub_file_check_and_fill(world, argv[1]);
		init_second_part(world);
		lets_cub(world);
	}
	else
		error_exit("World malloc error", world, NULL, -1);
	return (0);
}
