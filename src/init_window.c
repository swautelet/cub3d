/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonwautelet <simonwautelet@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:13:03 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/02 13:37:13 by simonwautel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//orientation de 0 a 90 haut gauche de 0  a pi / 2 radian
//orientation de 90 a 180 haut droite de pi/2 a pi radian 
//orientation de 180 a 270 bas droite de pi a 1.5 pi radian
//orientation de 270 a 360 bas gauche de 1.5 pi radian a  2 pi radian

void	init_window(t_param *world)
{
	world->video = mlx_init();
	world->window = mlx_new_window(world->video, world->screen_height, world->screen_width, "test");
	world->img = malloc(sizeof(t_data));
	world->img->img = mlx_new_image(world->video, world->screen_height, world->screen_width);
	world->img->bits_per_pixel = 0;
	world->img->line_length = 0;
	world->img->endian = 0;
	world->img->addr = mlx_get_data_addr(world->img->img, &world->img->bits_per_pixel, &world->img->line_length, &world->img->endian);
	draw_view(world);
	mlx_loop(world->video);
	free (world->img);
}

void	draw_view(t_param *world)
{
	int	offset;
	int	dist;

	offset = -30;
	while (offset <= 30)
	{
		dist = calcul_dist_till_wall(world, world->p_orient + offset);
		draw_col(world, dist, offset);
		//cast_ray(world);
		offset++;
	}
}

void	pixel_to_image(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_col(t_param *world, int dist, int offset)
{
	int	x;
	int	y;
	int	offset_wall;
	int	mid;
	int	i;

	x = (world->screen_width / 60) * (offset + 30);
	y = 0;
	offset_wall = (world->screen_height - 10) / dist / 2;
	mid = world->screen_height / 2;
	while (y <= world->screen_height)
	{
		if (y < mid - offset_wall)
		{
			i = -1;
			while (++i <= world->screen_width / 60)
				pixel_to_image(world->img, x, y, world->ceiling_color);
		}
		else if (y > mid + offset_wall)
		{
			i = -1;
			while (++i <= world->screen_width / 60)
				pixel_to_image(world->img, x, y, world->floor_color);
		}
		else
		{
			i = -1;
			while (++i <= world->screen_width / 60)
				pixel_to_image(world->img, x, y, world->wall_color);
		}
		y++;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
