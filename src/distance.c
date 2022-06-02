/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:54:13 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/02 16:00:44 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	calcul_dist_till_wall(t_param *world, double orientation)
{
	double	vert;
	double	hor;

	vert = next_vert_wall(world, orientation);
	hor = next_hor_wall(world, orientation);
	printf("vert = %f hor = %f\n", vert, hor);
	if (vert < hor)
		return (vert);
	else
		return (hor);
}

double	next_vert_wall(t_param *world, double orientation)
{
	double	decal;
	int		next_vert;

	next_vert = 0;
	if (orientation < 90 || orientation > 270)
	{
		next_vert = SIZE - (world->p_x_pos % SIZE);
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

double	next_hor_wall(t_param *world, double orientation)
{
	int	decal;
	int	next_hor;

	next_hor = 0;
	if (orientation > 0 && orientation < 180)
	{
		next_hor = (world->p_y_pos % SIZE) -  SIZE;
		decal = -1 * (next_hor * tan(degre_to_radiant(orientation)));
		while (check_up_wall(decal + world->p_y_pos, next_hor + world->p_x_pos, world) == FALSE)
		{
			next_hor -= SIZE;
			decal = -1 * (next_hor * tan(degre_to_radiant(orientation)));
		}
	}
	else if (orientation > 180)
	{
		next_hor =  SIZE - (world->p_y_pos % SIZE);
		decal = -1 * (next_hor * tan(degre_to_radiant(orientation)));
		while (check_down_wall(decal + world->p_y_pos, next_hor + world->p_x_pos, world)== FALSE)
		{
			next_hor += SIZE;
			decal = -1 * (next_hor * tan(degre_to_radiant(orientation)));
		}
	}
	if (orientation == 0 || orientation == 180)
		return (DBL_MAX);
	else
		return (sqrt(pow(next_hor, 2) + pow(decal, 2)));
}

double	degre_to_radiant(double degre)
{
	return (M_PI * degre / 180);
}
