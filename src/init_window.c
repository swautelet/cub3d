/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:13:03 by simonwautel       #+#    #+#             */
/*   Updated: 2022/06/08 14:18:48 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//orientation de 0 a 90 haut gauche de 0  a pi / 2 radian
//orientation de 90 a 180 haut droite de pi/2 a pi radian 
//orientation de 180 a 270 bas droite de pi a 1.5 pi radian
//orientation de 270 a 360 bas gauche de 1.5 pi radian a  2 pi radian

int	keyboard(int keycode, t_param *world)
{
	/*	All action that can possibly be made by the player	*/

	//printf("Keycode %d\n", keycode);
	if (keycode == 0)
		world->orient = (world->orient + 5) % 360;
	if (keycode == 2)
		world->orient = (world->orient - 5) % 360;
	if (keycode == 13)
		move_forward(world);
	if (keycode == 53)
		exit_cub3d(world);
	draw_view(world);
	return (0);
}

void	init_window(t_param *world)
{
	/*	Initialize a window and sets the hooks	*/

	world->img = malloc(sizeof(t_data));
	if (world->img)
	{
		world->video = mlx_init();
		world->window = mlx_new_window(world->video, SCREEN_WIDTH, SCREEN_HEIGHT, "test");
		world->img->img = mlx_new_image(world->video, SCREEN_WIDTH, SCREEN_HEIGHT);
		world->clean = mlx_new_image(world->video, SCREEN_WIDTH, SCREEN_HEIGHT);
		world->img->bits_per_pixel = 0;
		world->img->line_length = 0;
		world->img->endian = 0;
		world->img->addr = mlx_get_data_addr(world->img->img, &world->img->bits_per_pixel, &world->img->line_length, &world->img->endian);
		draw_view(world);
		mlx_hook(world->window, 2, 1L<<0, keyboard, world);
		mlx_loop_hook(world->video, draw_view, world);
		mlx_loop(world->video);
	}
	free (world->img);
}

int	draw_view(t_param *world)
{
	/*	Function that will output the visuals	*/

	double	offset;
	double	dist;

	offset = NBRAY;
	mlx_put_image_to_window(world->video, world->window, world->clean, 0, 0);
	while (offset >= 0)
	{
		// printf("offset = %f", offset);
		dist = calcul_dist_till_wall(world, world->orient + offset - (NBRAY / 2));
		if ((int)offset == 30)
		{
			// printf("i init p_front\n");
			world->player_front = dist;
		}
		// printf("dist = %f offset = %f\n", dist, offset);
		// printf("dist = %f offset = %f ray = %f\n", dist, offset, world->p_orient + offset - (NBRAY / 2));
		draw_col(world, dist, offset);
		offset -= 0.5;
	}
	// dist = calcul_dist_till_wall(world, world->p_orient);
	// world->p_front = dist;
	draw_minimap(world);
	mlx_put_image_to_window(world->video, world->window, world->img->img, 0, 0);
	return (0);
}

void	draw_col(t_param *world, double dist, double offset)
{
	int	x;
	int	y;
	int	offset_wall;
	int	mid;
	int	i;

	x = (SCREEN_WIDTH / NBRAY) * (offset + 1) * (-1);
	y = 0;
	offset_wall = ((SCREEN_HEIGHT / 2) / (dist / 30));
	mid = SCREEN_HEIGHT / 2;
	// printf("mid = %d, offset_wall = %d dist = %f\n", mid, offset_wall, dist);
	while (y <= SCREEN_HEIGHT)
	{
		if (y < mid - offset_wall)
		{
			i = -1;
			while (++i <= (SCREEN_WIDTH - 1)/ NBRAY)
				pixel_to_image(world->img, x + i, y, world->ceiling_color);
		}
		else if (y > mid + offset_wall)
		{
			i = -1;
			while (++i <= (SCREEN_WIDTH - 1) / NBRAY)
				pixel_to_image(world->img, x + i, y, world->floor_color);
		}
		else
		{
			i = -1;
			while (++i <= (SCREEN_WIDTH - 1) / NBRAY)
				pixel_to_image(world->img, x + i, y, world->wall_color);
		}
		y++;
	}
}
