/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_extractors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:29:58 by npinheir          #+#    #+#             */
/*   Updated: 2022/05/31 22:10:18 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	extract_sand_rose(t_mapD *map, char **split)
{
	if (len_array_2d(split) == 2)
	{
		if (ft_strsame(split[0], "NO"))
		{
			map->no = split[1];
			map->counter[0] += 1;
		}
		else if (ft_strsame(split[0], "SO"))
		{
			map->so = split[1];
			map->counter[1] += 1;
		}
		else if (ft_strsame(split[0], "WE"))
		{
			map->we = split[1];
			map->counter[2] += 1;
		}
		else if (ft_strsame(split[0], "EA"))
		{
			map->ea = split[1];
			map->counter[3] += 1;
		}
	}
}

void	extract_f_c(t_mapD *map, char **split)
{
	if (len_array_2d(split) == 2)
	{
		if (ft_strsame(split[0], "F"))
		{
			map->floor = to_hex_int(split[1]);
			map->counter[4] += 1;
		}
		else if (ft_strsame(split[0], "C"))
		{
			map->ceiling = to_hex_int(split[1]);
			map->counter[5] += 1;
		}
	}
}

void	extract_map(t_mapD *map)
{
	int		fd;
	char	*holder;
	//size_t	max_len;
	//size_t	max_high;

	holder = NULL;
	fd = open(map->path, O_RDONLY);
	if (!fd)
		error_exit("Failed to open the .cub file ");
	
}