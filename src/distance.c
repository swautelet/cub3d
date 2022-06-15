/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:54:13 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/15 17:59:57 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	calcul_dist_till_wall(t_param *world, double orientation, double *x_wall)
{
	double	vert;
	double	hor;
	double	dest;
	double	hor_x_wall;
	double	vert_x_wall;
	int		sub_door_vert;
	int		sub_door_hor;


	hor_x_wall = 0;
	vert_x_wall = 0;
	sub_door_hor = 0;
	sub_door_vert = 0;
	// printf(" orientation = %f\n", orientation);
	while (orientation < 0)
		orientation += 360;
	if (orientation >= 360)
		orientation = fmod(orientation, 360);
	vert = next_vert_wall(world, orientation, &vert_x_wall, &sub_door_vert);
	hor = next_hor_wall(world, orientation, &hor_x_wall, &sub_door_hor);
	if (vert < hor)
	{
		*x_wall = vert_x_wall;
		dest = vert;
		if (sub_door_vert == 3)
			world->flag_wall = DO;
		else if (orientation < 90 || orientation > 270)
			world->flag_wall = EA;
		else
			world->flag_wall = WE;
	}
	else
	{
		*x_wall = hor_x_wall;
		dest = hor;
		if (sub_door_hor == 3)
			world->flag_wall = DO;
		else if (orientation > 0 && orientation < 180)
			world->flag_wall = NO;
		else
			world->flag_wall = SO;
	}
	if (world->orient - orientation != 90 && world->orient - orientation != 270 && world->orient - orientation != -90 && world->orient - orientation != -270)
		dest = dest * cos(degre_to_radiant((double)world->orient - orientation));
	if (dest < 0)
		dest = dest * (-1);
	return (dest);
}

double	next_vert_wall(t_param *world, double orientation, double *vert_x_wall, int *sub_door_vert)
{
	double	decal;
	double	next_vert;
	double	tan_orientation;

	next_vert = 0;
	decal = 0;
	tan_orientation = tan(degre_to_radiant(orientation));
	if (orientation < 90 || orientation > 270) //look to right
	{
		next_vert = 1 - fmod(world->px_x_pos, 1);
		decal = (-1 * next_vert * tan_orientation);
		// if (orientation >= 0)
		// 	decal--;
		while ((*sub_door_vert = check_right_wall(decal + world->px_y_pos, world->px_x_pos + next_vert, world)) == FALSE)
		{
			next_vert += 1;
			decal -= tan_orientation;
		}
	}
	else if (orientation > 90 && orientation < 270) // look to left
	{
		next_vert = fmod(world->px_x_pos, 1) * (-1);
		decal = (-1 * next_vert * tan_orientation);
		// if (orientation < 180)
		// 	decal--;
		while ((*sub_door_vert = check_left_wall(world->px_y_pos + decal, world->px_x_pos + next_vert, world)) == FALSE)
		{
			next_vert -= 1;
			decal += tan_orientation;
		}
	}
	*vert_x_wall = fmod((decal + world->px_y_pos), 1);
	if (orientation == 270 || orientation == 90)
		return (DBL_MAX);
	else
		return (sqrt(pow(next_vert, 2) + pow(decal, 2)));
}

double	next_hor_wall(t_param *world, double orientation, double *hor_x_wall, int *sub_door_hor)
{
	double	decal;
	double	next_hor;
	double	cotan_orientation;

	next_hor = 0;
	decal = 0;
	cotan_orientation = (1 / tan(degre_to_radiant(orientation)));
	// if (orientation == 90.000)
		// printf("cotan  = %f orientation = %f\n", cotan_orientation, orientation);
	if (orientation > 0 && orientation < 180)
	{
		next_hor = fmod(world->px_y_pos, 1) * (-1);
		decal = cotan_orientation * (-next_hor);
		while ((*sub_door_hor = check_up_wall(next_hor + world->px_y_pos, decal + world->px_x_pos, world)) == FALSE) // look up
		{
			next_hor -= 1;
			decal += cotan_orientation;
		}
	}
	else if (orientation > 180)
	{
		next_hor = 1 - fmod(world->px_y_pos, 1);
		decal = -1 * (next_hor * cotan_orientation);
		while ((*sub_door_hor = check_down_wall(next_hor + world->px_y_pos, decal + world->px_x_pos, world)) == FALSE) // look down
		{
			next_hor += 1;
			decal -= cotan_orientation;
		}
	}
	*hor_x_wall = fmod((decal + world->px_x_pos), 1);
	if (orientation == 0 || orientation == 180)
		return (DBL_MAX);
	else
		return (sqrt(pow(next_hor, 2) + pow(decal, 2)));
}
