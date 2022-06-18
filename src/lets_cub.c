/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:34:58 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 11:31:40 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	keyboard_release(int keycode, t_param *world)
{
	(void)keycode;
	(void)world;
	return (0);
}

int	keyboard_press(int keycode, t_param *world)
{
	if (keycode == 53)
		succes_exit(world);
	return (0);
}

int	draw_view(t_param *world)
{
	(void)world;
	return (0);
}

void	lets_cub(t_param *world)
{
	init_mlx(world);
	draw_view(world);
	mlx_hook(world->window, 2, 1L << 0, keyboard_press, world);
	mlx_hook(world->window, 3, 1L << 1, keyboard_release, world);
	mlx_hook(world->window, 17, 1L << 5, succes_exit, world);
	mlx_loop_hook(world->instance, draw_view, world);
	mlx_loop(world->instance);
}
