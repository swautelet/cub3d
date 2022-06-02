/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extractor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:55:03 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/02 13:54:38 by npinheir         ###   ########.fr       */
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
		map->map_hight++;
		if (ft_strlen(holder) > map->map_len)
			map->map_len = ft_strlen(holder); // il manque une line si le fichier ne se termine pas par une ligne vide
	}
}

void	extract_map(t_mapD *map)
{
	int		fd;
	char	*holder;
	size_t	i;

	holder = NULL;
	i = 0;
	map->map = malloc(sizeof(char *) * map->map_hight + 1);
	if (!map->map)
		error_exit("Malloc error ");
	fd = open(map->path, O_RDONLY);
	if (!fd)
		error_exit("Failed to open the .cub file ");
	while (get_next_line(fd, &holder))
	{
		if (valid_map_line(holder) && ft_strlen(holder) > 1)
			map->map[i++] = ft_substr(holder, 0, ft_strlen(holder));
	}
}

// void	get_player_position(char **map)
// {
// 	size_t	x;
// 	size_t	y;

// 	x = 0;
// 	while (map[x])
// 	{
// 		y = 0;
// 		while (map[x][y])
// 		{
// 			if (ft_char_in_str(map[x][y], "NSEW"))
// 			{
// 				// player.x = x;
// 				// player.y = y;
// 				if (map[x][y] == 'N')
// 					//player.ori = 'N'
// 				else if (map[x][y] == 'S')
// 					//player.ori = 'S'
// 				else if (map[x][y] == 'E')
// 					//player.ori = 'E'
// 				else if (map[x][y] == 'W')
// 					//player.ori = 'W'
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }