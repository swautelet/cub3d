/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:03:54 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 12:10:11 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// typedef struct s_fuck{
// 	int	x0;
// 	int	y0;
// 	int	x1;
// 	int	y1;
// }t_fuck;

void	paint_square_map(unsigned int x, unsigned int y, t_param *w)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (++i < w->square_length)
	{
		j = -1;
		while (++j < w->square_length)
		{
			if (w->map[x][y] == '1')
				pixel_to_image(w->calque, y * w->square_length + i, x
					* w->square_length + j, create_trgb(100, 255, 255, 255));
			else if (w->map[x][y] == '0' || ft_char_in_str(w->map[x][y],
				"NSEW"))
				pixel_to_image(w->calque, y * w->square_length + i, x
					* w->square_length + j, create_trgb(100, 128, 128, 128));
			else if (w->map[x][y] == 'D')
				pixel_to_image(w->calque, y * w->square_length + i, x
					* w->square_length + j, create_trgb(100, 139, 69, 19));
			else if (w->map[x][y] == 'K')
				pixel_to_image(w->calque, y * w->square_length + i, x
					* w->square_length + j, create_trgb(100, 212, 175, 55));
		}
	}
}

void	draw_player_nose(t_param *world)
{
	unsigned int	new_x;
	unsigned int	new_y;
	t_fuck			d;

	if (world->square_length < 1)
		world->square_length = 1;
	new_x = world->map_x_pos + world->square_length
		* cos(degre_to_radiant(world->orient));
	new_y = world->map_y_pos - world->square_length
		* sin(degre_to_radiant(world->orient));
	if (new_x < (unsigned int)world->map_x_pos)
		new_x++;
	if (new_y < (unsigned int)world->map_y_pos)
		new_y++;
	d.x0 = world->map_x_pos;
	d.y0 = world->map_y_pos;
	d.x1 = new_x;
	d.y1 = new_y;
	bresenham(d, world);
}

void	draw_player(t_param *world)
{
	int	i;
	int	j;

	world->map_x_pos = ((world->px_x_pos) * world->square_length);
	world->map_y_pos = ((world->px_y_pos) * world->square_length);
	if (world->player_size == 0)
		world->player_size = 1;
	i = 0;
	while (i < world->player_size)
	{
		j = 0;
		while (j < world->player_size)
			pixel_to_image(world->calque, world->map_x_pos - (world->player_size
					/ 2) + i, world->map_y_pos - (world->player_size / 2)
				+ j++, 0x00000000);
		i++;
	}
	draw_player_nose(world);
}

void	draw_minimap(t_param *world)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < world->map_height)
	{
		j = 0;
		while (j < world->map_width)
			paint_square_map(i, j++, world);
		i++;
	}
	draw_player(world);
}
