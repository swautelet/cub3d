/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:17:04 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/18 12:31:35 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_left_wall(double y, double x, t_param *world)
{
	t_check	f;

	f.new_y = y;
	f.new_x = (x) - 1;
	if (f.new_y >= (int)world->map_height || f.new_x >= (int)world->map_width
		|| f.new_x < 0 || f.new_y < 0)
		return (TRUE);
	if (world->map[f.new_y][f.new_x] == 'K' && world->keyfound == FALSE)
	{
		world->keyfound = TRUE;
		world->dist_key = sqrt(pow((f.new_y + 0.5) - world->px_y_pos, 2)
				+ pow((f.new_x + 0.5) - world->px_x_pos, 2));
		if (world->flag_first_ray)
			world->x_wallkey = fmod(y, 1);
		else
			world->x_wallkey = 1;
	}
	if (world->map[f.new_y][f.new_x] == '1')
		return (TRUE);
	else if (world->map[f.new_y][f.new_x] == 'D')
		return (3);
	else
		return (FALSE);
}

int	check_right_wall(double y, double x, t_param *world)
{
	t_check	f;

	f.new_y = y;
	f.new_x = x;
	if (f.new_y >= (int)world->map_height || f.new_x >= (int)world->map_width
		|| f.new_x < 0 || f.new_y < 0)
		return (TRUE);
	if (world->map[f.new_y][f.new_x] == 'K' && world->keyfound == FALSE)
	{
		world->keyfound = TRUE;
		world->dist_key = sqrt(pow((f.new_y + 0.5) - world->px_y_pos, 2)
				+ pow((f.new_x + 0.5) - world->px_x_pos, 2));
		if (world->flag_first_ray)
			world->x_wallkey = fmod(y, 1);
		else
			world->x_wallkey = 1;
	}
	if (world->map[f.new_y][f.new_x] == '1')
		return (TRUE);
	else if (world->map[f.new_y][f.new_x] == 'D')
		return (3);
	else
		return (FALSE);
}

int	check_up_wall(double y, double x, t_param *world)
{
	t_check	f;

	f.new_y = (y) - 1;
	f.new_x = x;
	if (f.new_y >= (int)world->map_height || f.new_x >= (int)world->map_width
		|| f.new_y < 0 || f.new_x < 0)
		return (TRUE);
	if (world->map[f.new_y][f.new_x] == 'K' && world->keyfound == FALSE)
	{
		world->keyfound = TRUE;
		world->dist_key = sqrt(pow((f.new_y + 0.5) - world->px_y_pos, 2)
				+ pow((f.new_x + 0.5) - world->px_x_pos, 2));
		if (world->flag_first_ray)
			world->x_wallkey = fmod(y, 1);
		else
			world->x_wallkey = 1;
	}
	if (world->map[f.new_y][f.new_x] == '1')
		return (TRUE);
	else if (world->map[f.new_y][f.new_x] == 'D')
		return (3);
	else
		return (FALSE);
}

int	check_down_wall(double y, double x, t_param *world)
{
	t_check	f;

	f.new_y = y;
	f.new_x = x;
	if (f.new_y >= (int)world->map_height || f.new_x >= (int)world->map_width
		|| f.new_x < 0 || f.new_y < 0)
		return (TRUE);
	if (world->map[f.new_y][f.new_x] == 'K' && world->keyfound == FALSE)
	{
		world->keyfound = TRUE;
		world->dist_key = sqrt(pow((f.new_y + 0.5) - world->px_y_pos, 2)
				+ pow((f.new_x + 0.5) - world->px_x_pos, 2));
		if (world->flag_first_ray)
			world->x_wallkey = fmod(y, 1);
		else
			world->x_wallkey = 1;
	}
	if (world->map[f.new_y][f.new_x] == '1')
		return (TRUE);
	else if (world->map[f.new_y][f.new_x] == 'D')
		return (3);
	else
		return (FALSE);
}
