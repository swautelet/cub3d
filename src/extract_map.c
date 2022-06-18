/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:09:25 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 14:21:12 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_amount_key(t_param *world)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (world->map[y])
	{
		x = 0;
		while (world->map[y][x])
		{
			if (world->map[y][x] == 'K')
				world->amount_key++;
			x++;
		}
		y++;
	}
	if (world->amount_key > 1)
		error_exit("Too many keys in the map", world, NULL, -1);
}

void	fill_spaces(t_param *world)
{
	int	i;
	int	j;

	i = 0;
	while (i < world->map_height)
	{
		j = 0;
		while (j < world->map_width)
		{
			if (world->map[i][j] == ' ')
				world->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

void	process_map(t_param *world, int *fd, char **holder)
{
	int	i;

	i = 0;
	*holder = get_next_line(*fd);
	while (*holder)
	{
		if (valid_map_line(*holder) && ft_strlen(*holder) > 1)
		{
			world->map[i++] = ft_calloc(sizeof(char), world->map_width);
			ft_strlcpy(world->map[i - 1], *holder, ft_strlen(*holder) + 1);
		}
		else if (!valid_map_line(*holder))
			error_exit("Not a valid map line", world, *holder, -1);
		free(*holder);
		*holder = get_next_line(*fd);
	}
	free(*holder);
	world->map[i] = NULL;
}

void	extract_map(t_param *world)
{
	int		fd;
	char	*holder;

	holder = NULL;
	world->map = malloc(sizeof(char *) * world->map_height + 1);
	if (!world->map)
		error_exit("Map malloc error", world, NULL, -1);
	fd = open(world->path, O_RDONLY);
	if (fd == -1)
		error_exit("Failed to open the .cub file", world, NULL, -1);
	skip_non_map(world, &fd, &holder);
	process_map(world, &fd, &holder);
	fill_spaces(world);
	last_map_check(world);
	get_amount_key(world);
	get_player_position(world);
}
