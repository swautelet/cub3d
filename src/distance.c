/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:54:13 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/02 13:47:21 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	calcul_dist_till_wall(t_param *world, int orientation)
{
	int	vert;
	int	hor;

	vert = next_vert_wall(world, orientation);
	hor = next_hor_wall(world, orientation);
	if (vert < hor)
		return (vert);
	else
		return (hor);
}

double	next_vert_wall(t_param *world, int orientation)
{
	double	decal;
	int		next_vert;

	next_vert = 0;
	if (orientation < 90 || orientation > 270)
	{
		next_vert = SIZE - (world->p_x_pos % SIZE);
		// while ((next_vert + world->p_x_pos) % SIZE != 0)
		// 	next_vert++;
		decal = (-1 * next_vert * tan(degre_to_radiant(orientation)));
		while (check_left_wall(next_vert + world->p_x_pos, decal + world->p_y_pos, world) == FALSE)
		{
			next_vert += SIZE;
			decal = (-1 * next_vert * tan(degre_to_radiant(orientation)));
		}
	}
	else if (orientation < 90 || orientation > 270)
	{
		next_vert = (world->p_x_pos % SIZE) - SIZE;
		// while ((next_vert + world->p_x_pos) % SIZE != 0)
		// 	next_vert--;
		decal = (-1 * next_vert * tan(degre_to_radiant(orientation)));
		while (check_right_wall(next_vert + world->p_x_pos, decal + world->p_y_pos, world)== FALSE)
		{
			next_vert -= SIZE;
			decal = (-1 * next_vert * tan(degre_to_radiant(orientation)));
		}
	}
	if (orientation == 270 || orientation == 90)
		return (DBL_MAX);
	else
		return (sqrt(pow(next_vert, 2) + pow(decal, 2)));
}

double	next_hor_wall(t_param *world, int orientation)
{
	int	decal;
	int	next_hor;

	next_hor = 0;
	if (orientation > 0 && orientation < 180)
	{
		next_hor = (world->p_y_pos % SIZE) -  SIZE;
		// while ((next_hor + world->p_x_pos) % SIZE != 0)
		// 	next_hor++;
		decal = (next_hor * tan(degre_to_radiant(orientation)));
		while (check_up_wall(decal + world->p_y_pos, next_hor + world->p_x_pos, world) == FALSE)
		{
			next_hor -= SIZE;
			decal = (next_hor * tan(degre_to_radiant(orientation)));
		}
	}
	else if (orientation > 180)
	{
		next_hor =  SIZE - (world->p_y_pos % SIZE);
		// while ((next_hor + world->p_x_pos) % SIZE != 0)
		// 	next_hor--;
		decal = (next_hor * tan(degre_to_radiant(orientation)));
		while (check_down_wall(decal + world->p_y_pos, next_hor + world->p_x_pos, world)== FALSE)
		{
			next_hor += SIZE;
			decal = (next_hor * tan(degre_to_radiant(orientation)));
		}
	}
	if (orientation == 0 || orientation == 180)
		return (DBL_MAX);
	else
		return (sqrt(pow(next_hor, 2) + pow(decal, 2)));
}

double	degre_to_radiant(int degre)
{
	return (M_PI * degre / 180);
}
