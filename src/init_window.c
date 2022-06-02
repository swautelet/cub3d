/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:13:03 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/02 15:54:30 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//orientation de 0 a 90 haut gauche de 0  a pi / 2 radian
//orientation de 90 a 180 haut droite de pi/2 a pi radian 
//orientation de 180 a 270 bas droite de pi a 1.5 pi radian
//orientation de 270 a 360 bas gauche de 1.5 pi radian a  2 pi radian

int	keyboard(int keycode, t_param *world)
{
	(void)world;
	printf("Keycode %d\n", keycode);
	if (keycode == 0)
		world->p_orient -= 2;
	if (keycode == 2)
		world->p_orient += 2;
	return (0);
}

void	init_window(t_param *world)
{
	world->video = mlx_init();
	world->window = mlx_new_window(world->video, world->screen_width, world->screen_height, "test");
	world->img = malloc(sizeof(t_data));
	world->img->img = mlx_new_image(world->video, world->screen_width, world->screen_height);
	world->img->bits_per_pixel = 0;
	world->img->line_length = 0;
	world->img->endian = 0;
	world->img->addr = mlx_get_data_addr(world->img->img, &world->img->bits_per_pixel, &world->img->line_length, &world->img->endian);
	draw_view(world);
	mlx_hook(world->window, 2, 1L<<0, keyboard, world);
	mlx_loop_hook(world->video, draw_view, world);
	mlx_loop(world->video);
	free (world->img);
}

int	draw_view(t_param *world)
{
	double	offset;
	double	dist;

	offset = NBRAY;
	while (offset >= 0)
	{
		dist = calcul_dist_till_wall(world, world->p_orient + offset - (NBRAY / 2));
		draw_col(world, dist, offset);
		//printf("dist = %f offset = %f ray = %f\n", dist, offset, world->p_orient + offset - (NBRAY / 2));
		offset -= 0.1;
	}
	mlx_put_image_to_window(world->video, world->window, world->img->img, 0, 0);
	return (0);
}

void	pixel_to_image(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_col(t_param *world, double dist, double offset)
{
	int	x;
	int	y;
	int	offset_wall;
	int	mid;
	int	i;

	x = (world->screen_width / NBRAY) * offset;
	y = 0;
	offset_wall = ((world->screen_height - 10) / dist / 2) * 10;
	mid = world->screen_height / 2;
	while (y <= world->screen_height)
	{
		if (y < mid - offset_wall)
		{
			i = -1;
			while (++i <= (world->screen_width - 1)/ NBRAY)
				pixel_to_image(world->img, x, y, world->ceiling_color);
		}
		else if (y > mid + offset_wall)
		{
			i = -1;
			while (++i <= (world->screen_width - 1) / NBRAY)
				pixel_to_image(world->img, x, y, world->floor_color);
		}
		else
		{
			i = -1;
			while (++i <= (world->screen_width - 1) / NBRAY)
				pixel_to_image(world->img, x, y, world->wall_color);
		}
		y++;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
