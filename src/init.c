/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:12:26 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 16:01:47 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_textures(t_param *world)
{
	world->img->addr = mlx_get_data_addr(world->img->img,
			&world->img->bits_per_pixel, &world->img->line_length,
			&world->img->endian);
	world->calque->addr = mlx_get_data_addr(world->calque->img,
			&world->calque->bits_per_pixel, &world->calque->line_length,
			&world->calque->endian);
	world->texture[NO].addr = mlx_get_data_addr(world->texture[NO].img,
			&world->texture[NO].bits_per_pixel, &world->texture[NO].line_length,
			&world->texture[NO].endian);
	world->texture[SO].addr = mlx_get_data_addr(world->texture[SO].img,
			&world->texture[SO].bits_per_pixel, &world->texture[SO].line_length,
			&world->texture[SO].endian);
	world->texture[WE].addr = mlx_get_data_addr(world->texture[WE].img,
			&world->texture[WE].bits_per_pixel, &world->texture[WE].line_length,
			&world->texture[WE].endian);
	world->texture[EA].addr = mlx_get_data_addr(world->texture[EA].img,
			&world->texture[EA].bits_per_pixel, &world->texture[EA].line_length,
			&world->texture[EA].endian);
	world->texture[DO].addr = mlx_get_data_addr(world->texture[DO].img,
			&world->texture[DO].bits_per_pixel, &world->texture[DO].line_length,
			&world->texture[DO].endian);
	world->texture[KE].addr = mlx_get_data_addr(world->texture[KE].img,
			&world->texture[KE].bits_per_pixel, &world->texture[KE].line_length,
			&world->texture[KE].endian);
}

void	init_textures(t_param *world)
{
	world->texture[NO].img = mlx_xpm_file_to_image(world->instance, world->no,
			&(world->texture[NO].x_size), &(world->texture[NO].y_size));
	world->texture[SO].img = mlx_xpm_file_to_image(world->instance, world->so,
			&(world->texture[SO].x_size), &(world->texture[SO].y_size));
	world->texture[WE].img = mlx_xpm_file_to_image(world->instance, world->we,
			&(world->texture[WE].x_size), &(world->texture[WE].y_size));
	world->texture[EA].img = mlx_xpm_file_to_image(world->instance, world->ea,
			&(world->texture[EA].x_size), &(world->texture[EA].y_size));
	world->texture[DO].img = mlx_xpm_file_to_image(world->instance,
			"./texture/door.xpm", &(world->texture[DO].x_size),
			&(world->texture[DO].y_size));
	world->texture[KE].img = mlx_xpm_file_to_image(world->instance,
			"./texture/keyblade.xpm", &(world->texture[KE].x_size),
			&(world->texture[KE].y_size));
	if (!world->texture[NO].img || !world->texture[SO].img
		|| !world->texture[WE].img || !world->texture[EA].img
		|| !world->texture[DO].img || ! world->texture[KE].img)
		error_exit("Texture doesn't exists", world, NULL, -1);
	set_textures(world);
}

void	init_mlx(t_param *world)
{
	world->img = malloc(sizeof(t_img));
	world->texture = malloc(sizeof(t_img) * 6);
	world->calque = malloc(sizeof(t_img));
	if (!world->img || !world->texture || !world->calque)
		error_exit("Images malloc error", world, NULL, -1);
	world->instance = mlx_init();
	world->window = mlx_new_window(world->instance, world->nb_ray,
			SCREEN_HEIGHT, "Cub3D");
	world->img->img = mlx_new_image(world->instance, world->nb_ray,
			SCREEN_HEIGHT);
	world->calque->img = mlx_new_image(world->instance, world->nb_ray,
			SCREEN_HEIGHT);
	world->calque->x_size = world->nb_ray;
	world->calque->y_size = SCREEN_HEIGHT;
	world->img->x_size = world->nb_ray;
	world->img->y_size = SCREEN_HEIGHT;
	init_textures(world);
}

static	void	init_world2(t_param *world)
{
	world->calque = NULL;
	world->nb_ray = ANGLEVISION / ECAR;
	world->mid = ANGLEVISION / 2;
	world->x_wallkey = 0;
	world->dist_key = -1;
	world->keyfound = FALSE;
	world->flag_wall = 0;
	world->half_screen = SCREEN_HEIGHT / 2;
	world->flag_back = FALSE;
	world->flag_front = FALSE;
	world->flag_left = FALSE;
	world->flag_right = FALSE;
	world->flag_rotateleft = FALSE;
	world->flag_rotateright = FALSE;
	world->key_picked = FALSE;
}

void	init_world(t_param *world)
{
	world->px_x_pos = 0;
	world->px_y_pos = 0;
	world->map_x_pos = 0;
	world->map_y_pos = 0;
	world->orient = 0;
	world->limit = MOVE * 2;
	world->map = NULL;
	world->map_height = 0;
	world->map_width = 0;
	world->map_start = 0;
	world->path = NULL;
	world->no = NULL;
	world->so = NULL;
	world->we = NULL;
	world->ea = NULL;
	world->floor_color = 0;
	world->ceiling_color = 0;
	world->amount_key = 0;
	world->counter = NULL;
	world->instance = NULL;
	world->window = NULL;
	world->img = NULL;
	world->texture = NULL;
	init_world2(world);
}
