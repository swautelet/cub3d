/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:34:58 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/19 13:09:51 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
