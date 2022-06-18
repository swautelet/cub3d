/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:05:56 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 11:45:03 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	clean_close_mlx(t_param *world)
{
	int	i;

	i = 0;
	if (world->texture)
	{
		while (i < 6)
			mlx_destroy_image(world->instance, world->texture[i++].img);
	}
	if (world->img)
		mlx_destroy_image(world->instance, world->img->img);
	if (world->calque)
		mlx_destroy_image(world->instance, world->calque->img);
	if (world->window)
		mlx_destroy_window(world->instance, world->window);
}

int	succes_exit(t_param *world)
{
	clean_close_mlx(world);
	free_world(world);
	system("leaks cub3D");
	exit(EXIT_SUCCESS);
	return (0);
}

void	error_exit(char *message, t_param *world, char *str_tr_free,
	int fd_to_close)
{
	clean_close_mlx(world);
	free_world(world);
	free(str_tr_free);
	if (fd_to_close != -1)
		close(fd_to_close);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	system("leaks cub3D");
	exit(EXIT_FAILURE);
}
