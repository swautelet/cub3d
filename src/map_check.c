/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:35:41 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 15:11:38 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map_end(t_param *world, size_t i)
{
	int	diff;
	int	j;

	diff = 0;
	if ((int)i < world->map_height - 1)
	{
		if (ft_strlen(world->map[i]) != ft_strlen(world->map[i + 1]))
			diff = ft_strlen(world->map[i]) - ft_strlen(world->map[i + 1]);
		if (world->map[i][ft_strlen(world->map[i]) - 1] != '1'
			&& world->map[i][ft_strlen(world->map[i]) - 1] != 'v')
			error_exit("Map not closed", world, NULL, -1);
		j = -1;
		while (++j < diff - 1)
		{
			if (world->map[i][ft_strlen(world->map[i + 1]) + j] != '1')
				error_exit("Map not closed", world, NULL, -1);
		}
		j = -1;
		while (++j < (-1 * diff))
		{
			if (world->map[i + 1][ft_strlen(world->map[i]) + j] != '1')
				error_exit("Map not closed", world, NULL, -1);
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
			error_exit("Map not closed", world, NULL, -1);
		check_map_end(world, i);
		i++;
	}
	i = 0;
	while (i < ft_strlen(world->map[0]))
	{
		if (world->map[0][i] != '1' && world->map[0][i] != 'v')
			error_exit("Map not closed", world, NULL, -1);
		i++;
	}
	i = 0;
	while (i < ft_strlen(world->map[world->map_height - 1]))
	{
		if ((world->map[world->map_height - 1][i] != '1'
			&& world->map[world->map_height - 1][i] != 'v'))
			error_exit("Map not closed", world, NULL, -1);
		i++;
	}
}

int	valid_map_line(const char *holder)
{
	char	*base;
	size_t	i;

	base = " 01NSEWDK";
	i = 0;
	if (!*holder)
		return (0);
	while (holder[i])
	{
		if (!ft_char_in_str(holder[i++], base))
			return (0);
	}
	return (1);
}

void	map_data_check(t_param *world, char *holder)
{
	if (valid_map_line(holder) && ft_strlen(holder) > 1)
	{
		world->map_height++;
		if ((int)ft_strlen(holder) > world->map_width)
			world->map_width = ft_strlen(holder);
	}
}
