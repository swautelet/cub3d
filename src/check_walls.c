/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:17:04 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/07 17:45:23 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_left_wall(int x, int y, t_param *world)
{
	int	new_x;
	int	new_y;

	new_y = y / SIZE;
	new_x = (x / SIZE) - 1;
	if (new_y >= (int)world->map_height || new_x >= (int)world->map_width || new_x < 0 || new_y < 0)
		return (TRUE);
	if (world->map[new_y][new_x] == '1')
	{
		// printf("left found y = %d x = %d\n",(y / SIZE),  (x / SIZE) - 1);
		return (TRUE);
	}
	else
		return (FALSE);
}

int	check_right_wall(int x, int y, t_param *world)
{
	int	new_x;
	int	new_y;

	new_y = y / SIZE;
	new_x = x / SIZE;
	if (new_y >= (int)world->map_height || new_x >= (int)world->map_width || new_x < 0 || new_y < 0)
		return (TRUE);
	if (world->map[new_y][new_x] == '1')
	{
		// printf("right found y = %d x = %d\n",(y / SIZE),  (x / SIZE));
		return (TRUE);
	}
	else
		return (FALSE);
}

int	check_up_wall(int y, int x, t_param *world)
{
	int	new_x;
	int	new_y;

	// printf("test\n");
	new_y = (y / SIZE) - 1;
	new_x = x / SIZE;
	if (new_y >= (int)world->map_height || new_x >= (int)world->map_width || new_y < 0 || new_x < 0)
		return (TRUE);
	if (x % 64 == 0)
	{
		if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x - 1] == '1')
			return (TRUE);
	}
	if (world->map[new_y][new_x] == '1')
	{
	// printf("up found y = %d x = %d\n",(y / SIZE) - 1,  (x / SIZE));
		return (TRUE);
	}
	else
		return (FALSE);
}

int	check_down_wall(int y, int x, t_param *world)
{
	int	new_x;
	int	new_y;

	new_y = y / SIZE;
	new_x = x / SIZE;
	if (new_y >= (int)world->map_height || new_x >= (int)world->map_width || new_x < 0 || new_y < 0)
		return (TRUE);
	if (x % 64 == 0)
	{
		if (world->map[new_y][new_x] == '1' || world->map[new_y][new_x - 1] == '1')
			return (TRUE);
	}
	if (world->map[new_y][new_x] == '1')
	{
		// printf("down found y = %d x = %d\n",(y / SIZE),  (x / SIZE));
		return (TRUE);
	}
	else
		return (FALSE);
}
