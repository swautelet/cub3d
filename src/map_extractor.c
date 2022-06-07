/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:55:03 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/08 00:28:35 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	valid_map_line(const char *holder)
{
	char	*base;
	size_t	i;

	base = " 01NSEW";
	i = 0;
	while (holder[i])
	{
		if (!ft_char_in_str(holder[i], base))
			return (0);
		i++;
	}
	return (1);
}

void	map_data_check(t_mapD *map, const char *holder)
{
	if (valid_map_line(holder) && ft_strlen(holder) > 1)
	{
		map->map_height++;
		if (ft_strlen(holder) > map->map_length)
			map->map_length = ft_strlen(holder); // il manque une ligne si le fichier ne se termine pas par une ligne vide
	}
}

void	get_player_position(t_mapD *map)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (map->map[x])
	{
		y = 0;
		while (map->map[x][y])
		{
			if (ft_char_in_str(map->map[x][y], "NSEW"))
			{
				map->pos_x = y;
				map->pos_y = x;
				if (map->map[x][y] == 'N')
					map->orient = 90;
				else if (map->map[x][y] == 'S')
					map->orient = 270;
				else if (map->map[x][y] == 'E')
					map->orient = 0;
				else if (map->map[x][y] == 'W')
					map->orient = 180;
			}
			y++;
		}
		x++;
	}
}

void	extract_map(t_mapD *map)
{
	int		fd;
	char	*holder;
	size_t	i;

	holder = NULL;
	i = 0;
	map->map = malloc(sizeof(char *) * map->map_height + 1);
	if (!map->map)
		error_exit("Malloc error ");
	fd = open(map->path, O_RDONLY);
	if (!fd)
		error_exit("Failed to open the .cub file ");
	while (get_next_line(fd, &holder))
	{
		if (valid_map_line(holder) && ft_strlen(holder) > 1)
		{
			map->map[i] = ft_calloc(sizeof(char), map->map_length + 1);
			ft_strlcpy(map->map[i++], holder, ft_strlen(holder) + 1);
		}
	}
	get_player_position(map);
}
