/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:53:32 by swautele          #+#    #+#             */
/*   Updated: 2022/06/09 15:10:35 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_color_from_img(t_data *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->x_size + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
