/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:17:04 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/07 12:35:35 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_left_wall(int x, int y, t_param *world)
{
	if ((y / SIZE) >= (int)world->map_height || (x / SIZE) - 1 >= (int)world->map_width || (x / SIZE) - 1 < 0 || y / SIZE < 0)
		return (TRUE);
	if (world->map[(y / SIZE)][(x / SIZE) - 1] == '1')
	{
		// printf("left found y = %d x = %d\n",(y / SIZE),  (x / SIZE) - 1);
		return (TRUE);
	}
	else
		return (FALSE);
}

int	check_right_wall(int x, int y, t_param *world)
{
	if ((y / SIZE) >= (int)world->map_height || x / SIZE >= (int)world->map_width || (x / SIZE) < 0 || (y / SIZE) < 0)
		return (TRUE);
	if (world->map[(y / SIZE)][(x / SIZE)] == '1')
	{
		// printf("right found y = %d x = %d\n",(y / SIZE),  (x / SIZE));
		return (TRUE);
	}
	else
		return (FALSE);
}

int	check_up_wall(int y, int x, t_param *world)
{
	// printf("test\n");
	if ((y / SIZE) - 1 >= (int)world->map_height || x / SIZE >= (int)world->map_width || (y / SIZE) - 1 < 0 || x / SIZE < 0)
		return (TRUE);
	if (world->map[(y / SIZE) - 1][(x / SIZE)] == '1')
	{
	// printf("up found y = %d x = %d\n",(y / SIZE) - 1,  (x / SIZE));
		return (TRUE);
	}
	else
		return (FALSE);
}

int	check_down_wall(int y, int x, t_param *world)
{
	if ((y / SIZE)>= (int)world->map_height || x / SIZE >= (int)world->map_width || (x / SIZE) < 0 || (y / SIZE) < 0)
		return (TRUE);
	if (world->map[(y / SIZE)][(x / SIZE)] == '1')
	{
		// printf("down found y = %d x = %d\n",(y / SIZE),  (x / SIZE));
		return (TRUE);
	}
	else
		return (FALSE);
}
