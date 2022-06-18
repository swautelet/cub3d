/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:02:55 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 15:19:41 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
