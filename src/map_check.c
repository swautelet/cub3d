/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:34:40 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 17:20:48 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map_end(t_param *world, size_t i)
{
	int	diff;
	int	j;

	diff = 0;
	if (i < world->map_height - 1)
	{
		if (ft_strlen(world->map[i]) != ft_strlen(world->map[i + 1]))
			diff = ft_strlen(world->map[i]) - ft_strlen(world->map[i + 1]);
		//printf("line %zu : %zu, line %zu :%zu, Diff : %d\n",i, ft_strlen(world->map[i]), i + 1, ft_strlen(world->map[i + 1]), diff);
		if (world->map[i][ft_strlen(world->map[i]) - 1] != '1' && world->map[i][ft_strlen(world->map[i]) - 1] != 'v')
			error_exit("Corrupted .cub file", world, NULL, -1);
		j = 0;
		while (j < diff - 1)
		{
			if (world->map[i][ft_strlen(world->map[i + 1]) + j] != '1')
				error_exit("Corrupted .cub file", world, NULL, -1);
			j++;
		}
		j = 0;
		while (j < (-1 * diff))
		{
			if (world->map[i + 1][ft_strlen(world->map[i]) + j] != '1')
				error_exit("Corrupted .cub file", world, NULL, -1);
			j++;
		}
	}
}

void	last_map_check(t_param *world)
{
	size_t	i;

	i = 0;
	while (world->map[i])
	{
		if (world->map[i][0] != '1' && world->map[i][0] != 'v')
			error_exit("Corrupted .cub file", world, NULL, -1);
		check_map_end(world, i);
		i++;
	}
	i = 0;
	while (i < ft_strlen(world->map[0]))
	{
		if (world->map[0][i] != '1' && world->map[0][i] != 'v')
			error_exit("Corrupted .cub file", world, NULL, -1);
		i++;
	}
	i = 0;
	while (i < ft_strlen(world->map[world->map_height - 1]))
	{
		if ((world->map[world->map_height - 1][i] != '1' && world->map[world->map_height - 1][i] != 'v'))
			error_exit("Corrupted .cub file", world, NULL, -1);
		i++;
	}
}

int	valid_map_line(const char *holder)
{
	char	*base;
	size_t	i;

	base = " 01NSEWDK";
	i = 0;
	while (holder[i])
	{
		if (!ft_char_in_str(holder[i++], base))
			return (0);
	}
	return (1);
}

void	map_data_check(t_param *world, const char *holder)
{
	if (valid_map_line(holder) && ft_strlen(holder) > 1)
	{
		world->map_height++;
		if (ft_strlen(holder) > world->map_width)
			world->map_width = ft_strlen(holder); // il manque une ligne si le fichier ne se termine pas par une ligne vide
	}
}
