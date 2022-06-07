/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:13:27 by swautele          #+#    #+#             */
/*   Updated: 2022/06/07 11:30:57 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_param *world)
{
	// printf("i try to move p_front = %f\n", world->p_front);
	printf("i moved to %d %d and p_orient = %d p_front = %f\n", world->p_y_pos, world->p_x_pos, world->p_orient,  world->p_front);
	if (world->p_front > 8.000)
	{
		if (world->p_orient == 0)
			world->p_x_pos += 8;
		else if (world->p_orient == 90)
			world->p_y_pos -= 8;
		else if (world->p_orient == 180)
			world->p_x_pos -= 8;
		else if (world->p_orient == 270)
			world->p_y_pos += 8;
		else
		{
			world->p_x_pos += cos(degre_to_radiant(world->p_orient)) * 8;
			world->p_y_pos -= sin(degre_to_radiant(world->p_orient)) * 8;
		}
		// draw_view(world);
	}
}
