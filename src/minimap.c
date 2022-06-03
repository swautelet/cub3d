/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:03:54 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/03 18:12:20 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	paint_map(unsigned int x, unsigned int y, unsigned int len, t_param *world)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (world->map_data->map[x][y] == '1')
				pixel_to_image(world->img, y * len + i, x * len + j, 0xaaffaa00);
			else if (world->map_data->map[x][y] == ' ' || !world->map_data->map[x][y])
			{
				j++;
				continue;
			}
			else
				pixel_to_image(world->img, y * len + i, x * len + j, 0xaa00ff00);
			j++;
		}
		i++;
	}
}

/*	Algorithme de Bresenham, celle-ci dessine les lignes entre
	deux points.	*/

void	bresenham(int x0, int y0, int x1, int y1, t_param * world)
{
	int	dx, dy, sx, sy, err, e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	if (dx > dy)
		err = dx / 2;
	else
		err = -dy / 2;
	while (1)
	{
		pixel_to_image(world->img, x0, y0, 0x00000000);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_player_nose(t_param *world)
{
	// end point = x = r cosθ and y = r sinθ
	unsigned int	new_x;
	unsigned int	new_y;

	new_x = world->p_map_x + (world->p_front / 4 * cos(degre_to_radiant(world->p_orient)));
	new_y = world->p_map_y - (world->p_front / 4 * sin(degre_to_radiant(world->p_orient)));

	bresenham(world->p_map_x + world->p_size, world->p_map_y + world->p_size, new_x + world->p_size, new_y + world->p_size, world);
}

void	draw_player(t_param *world, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;


	world->p_map_x = 0;
	world->p_map_y = 0;
	world->p_size = len / 2;
	world->p_map_x = (((world->p_x_pos / SIZE)) + ((world->p_x_pos % SIZE) / SIZE)) * len;
	world->p_map_y = (((world->p_y_pos / SIZE)) + ((world->p_y_pos % SIZE) / SIZE)) * len;
	//printf("p_map_x = ");
	i = 0;
	while (i < world->p_size)
	{
		j = 0;
		while (j < world->p_size)
			pixel_to_image(world->img, world->p_map_x + (world->p_size / 2) + i, world->p_map_y + (world->p_size / 2) + j++, 0x00000000);
		i++;
	}
	world->p_x_mid = world->p_map_x + world->p_size;
	world->p_y_mid = world->p_map_y + world->p_size;
	draw_player_nose(world);
}

void	draw_minimap(t_param *world)
{
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;
	// printf("Max len of minimap chunk : %d\n", map_len_chunk);
	// printf("Max height of minimap chunk : %d\n", map_hight_chunk);
	if (world->map_data->map_len > world->map_data->map_hight)
		len = world->map_data->map_len / 2;
	else
		len = world->map_data->map_hight / 2;
	i = 0;
	//printf("len = %d\n", len);
	while (i < world->map_data->map_hight)
	{
		j = 0;
		while (j < world->map_data->map_len)
			paint_map(i, j++, len, world);
		i++;
	}
	draw_player(world, len);
}