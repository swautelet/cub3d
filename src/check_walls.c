/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:17:04 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/02 13:52:18 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_left_wall(int x, int y, t_param *world)
{
	if (world->map[y / SIZE][(x / SIZE - 1)] == '1')
		return (TRUE);
	else
		return (FALSE);
}

int	check_right_wall(int x, int y, t_param *world)
{
	if (world->map[y / SIZE][x / SIZE] == '1')
		return (TRUE);
	else
		return (FALSE);
}

int	check_up_wall(int x, int y, t_param *world)
{
	if (world->map[(y / SIZE) - 1][x / SIZE] == '1')
		return (TRUE);
	else
		return (FALSE);
}

int	check_down_wall(int x, int y, t_param *world)
{
	if (world->map[y / SIZE][x / SIZE] == '1')
		return (TRUE);
	else
		return (FALSE);
}
