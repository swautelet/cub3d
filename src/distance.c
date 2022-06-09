/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:54:13 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/09 12:38:49 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	calcul_dist_till_wall(t_param *world, double orientation)
{
	double	vert;
	double	hor;
	double	dest;

	while (orientation < 0)
		orientation += 360;
	// printf("orientation = %f\n", orientation);
	vert = next_vert_wall(world, orientation);
	// printf("between\n");
	hor = next_hor_wall(world, orientation);
	// printf("vert = %f hor = %f\n", vert, hor);
	if (vert < hor)
		dest = vert;
	else
		dest = hor;
	dest = dest * cos(degre_to_radiant(world->orient - orientation));
	return (dest);
}

double	next_vert_wall(t_param *world, double orientation)
{
	double	decal;
	int		next_vert;

	next_vert = 0;
	// printf("orientation = %f\n", orientation);
	if (orientation < 90 || orientation > 270)
	{
		next_vert = SIZE - (world->px_x_pos % SIZE);
		decal = (-1 * next_vert * tan(degre_to_radiant(orientation)));
		// printf("here\n");
		while (check_right_wall(next_vert + world->px_x_pos, decal + world->px_y_pos, world) == FALSE)
		{
			next_vert += SIZE;
			decal = (-1 * next_vert * tan(degre_to_radiant(orientation)));
		}
		// printf("two\n");
	}
	else if (orientation > 90 && orientation < 270)
	{
		next_vert = (world->px_x_pos % SIZE) * (-1);
		decal = (-1 * next_vert * tan(degre_to_radiant(orientation)));
		while (check_left_wall(next_vert + world->px_x_pos, decal + world->px_y_pos, world)== FALSE)
		{
			next_vert -= SIZE;
			decal = (-1 * next_vert * tan(degre_to_radiant(orientation)));
		}
	// printf("next vert = %d, decal = %f\n", next_vert, decal);
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
		next_hor = (world->px_y_pos % SIZE) * (-1);
		decal = -1 * (next_hor * (1 / tan(degre_to_radiant(orientation))));
		// printf("look for up \n");
		while (check_up_wall(next_hor + world->px_y_pos, decal + world->px_x_pos, world) == FALSE)
		{
			next_hor -= SIZE;
			decal = -1 * (next_hor * (1 / tan(degre_to_radiant(orientation))));
		}
	}
	else if (orientation > 180)
	{
		next_hor =  SIZE - (world->px_y_pos % SIZE);
		decal = -1 * (next_hor * (1 / tan(degre_to_radiant(orientation))));
		// printf("look for down \n");
		while (check_down_wall(next_hor + world->px_y_pos, decal + world->px_x_pos, world)== FALSE)
		{
			next_hor += SIZE;
			decal = -1 * (next_hor * (1 / tan(degre_to_radiant(orientation))));
		}
	}
	if (orientation == 0 || orientation == 180)
		return (DBL_MAX);
	else
		return (sqrt(pow(next_hor, 2) + pow(decal, 2)));
}

