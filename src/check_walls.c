/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:17:04 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/02 15:31:24 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_left_wall(int x, int y, t_param *world)
{
	if ((y / SIZE) >= (int)world->map_height || (x / SIZE) - 1 >= (int)world->map_width)
		return (TRUE);
	if (world->map[y / SIZE][(x / SIZE - 1)] == '1')
		return (TRUE);
	else
		return (FALSE);
}

int	check_right_wall(int x, int y, t_param *world)
{
	if ((y / SIZE) >= (int)world->map_height || x / SIZE >= (int)world->map_width)
		return (TRUE);
	if (world->map[y / SIZE][x / SIZE] == '1')
		return (TRUE);
	else
		return (FALSE);
}

int	check_up_wall(int x, int y, t_param *world)
{
	if ((y / SIZE) - 1 >= (int)world->map_height || x / SIZE >= (int)world->map_width)
		return (TRUE);
	if (world->map[(y / SIZE) - 1][x / SIZE] == '1')
		return (TRUE);
	else
		return (FALSE);
}

int	check_down_wall(int x, int y, t_param *world)
{
	if ((y / SIZE) >= (int)world->map_height || x / SIZE >= (int)world->map_width)
		return (TRUE);
	if (world->map[y / SIZE][x / SIZE] == '1')
		return (TRUE);
	else
		return (FALSE);
}
