/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:16:02 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 14:07:59 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*space_string(size_t len, t_param *world)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		error_exit("Space string malloc error ", world, NULL, -1);
	while (i < len)
		res[i++] = '\0';
	res[i] = '\0';
	return (res);
}

void	pixel_to_image(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	degre_to_radiant(double degre)
{
	return (M_PI * degre / 180);
}
