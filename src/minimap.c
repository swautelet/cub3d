/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:03:54 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/08 01:02:54 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	paint_square_map(unsigned int x, unsigned int y, unsigned int square_length, t_param *world)
{
	unsigned int i;
	unsigned int j;

	i = 1;	// offset pour afficher une fausse grille
	while (i < square_length)
	{
		j = 1;
		while (j < square_length)
		{
			if (world->map_data->map[x][y] == '1')
				pixel_to_image(world->img, y * square_length + i, x * square_length + j, 0xaaffaa00);	// couleur des cases mur
			else if (world->map_data->map[x][y] == ' ' || !world->map_data->map[x][y])
			{
				j++;
				continue;
			}
			else
				pixel_to_image(world->img, y * square_length + i, x * square_length + j, 0xaa00ff00);	// couleur des cases terrain
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

	if (!world->map_data->ray_mode)
	{
		new_x = world->p_map_x + (world->p_front / 7 * cos(degre_to_radiant(world->p_orient)));
		new_y = world->p_map_y - (world->p_front / 7 * sin(degre_to_radiant(world->p_orient)));
	}
	else
	{
		new_x = world->p_map_x + (20 * cos(degre_to_radiant(world->p_orient)));
		new_y = world->p_map_y - (20 * sin(degre_to_radiant(world->p_orient)));
	}
	bresenham(world->p_map_x, world->p_map_y, new_x, new_y, world);
}

void	draw_player(t_param *world, unsigned int square_length)
{
	unsigned int	i;
	unsigned int	j;


	world->p_map_x = 0;
	world->p_map_y = 0;
	world->p_size = square_length / 2;
	world->p_map_x = ((((world->p_x_pos / SIZE) * square_length) + ((world->p_x_pos % SIZE) * square_length / SIZE)));
	world->p_map_y = ((((world->p_y_pos / SIZE) * square_length) + ((world->p_y_pos % SIZE) * square_length / SIZE)));
	//printf("p_map_x = ");
	i = 0;
	while (i < world->p_size)
	{
		j = 0;
		while (j < world->p_size)
			pixel_to_image(world->img, world->p_map_x - (world->p_size / 3) + i, world->p_map_y - (world->p_size / 3) + j++, 0x00000000);
		i++;
	}
	world->p_x_mid = world->p_map_x + world->p_size;
	world->p_y_mid = world->p_map_y + world->p_size;
	draw_player_nose(world);
}

void	draw_minimap(t_param *world)
{
	unsigned int	square_length; // longueur des cotes des carres de la minimap
	unsigned int	i;
	unsigned int	j;

	if (world->map_data->map_length > world->map_data->map_height)
		square_length = (SCREEN_WIDTH / 3) / world->map_data->map_length + world->map_data->minimap_zoom;
	else
		square_length = (SCREEN_HEIGHT / 3) / world->map_data->map_height + world->map_data->minimap_zoom;
	i = 0;
	while (i < world->map_data->map_height)
	{
		j = 0;
		while (j < world->map_data->map_length)
			paint_square_map(i, j++, square_length, world);
		i++;
	}
	draw_player(world, square_length);
}