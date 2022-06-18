/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 11:53:50 by swautele          #+#    #+#             */
/*   Updated: 2022/06/18 12:10:49 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3D.h"

void	init_second_part(t_param *world)
{
	if (world->map_width > world->map_height)
		world->square_length = (world->nb_ray / 3) / world->map_width;
	else
		world->square_length = (SCREEN_HEIGHT / 3) / world->map_height;
	world->player_size = world->square_length / 3;
}
