/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 01:09:25 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 02:29:57 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	fill_spaces(t_param *world)
{
	size_t	i;
	size_t	j;

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
	char	*end_line;
	int		i;

	end_line = NULL;
	i = 0;
	while ((*holder = get_next_line(*fd)))
	{
		end_line = space_string(world->map_width - ft_strlen(*holder), world);
		if (valid_map_line(*holder) && ft_strlen(*holder) > 1)
			world->map[i++] = ft_strjoin(*holder, end_line);
		else if (!valid_map_line(*holder))
			error_exit("Not a valid map line", world, end_line, -1);
		free(end_line);
		free(*holder);
	}
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
	get_player_position(world);
}