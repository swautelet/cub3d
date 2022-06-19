/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:23:35 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/19 13:24:17 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_map_start(t_param *world, const char *holder)
{
	static int	start_counting;
	static int	i;

	if (counter_check(world->counter) == 2)
		error_exit("Counter not full", world, NULL, -1);
	if (counter_check(world->counter) == 0 && start_counting <= 1)
	{
		world->map_start = i;
		if (ft_strlen(holder) > 1)
			start_counting++;
	}
	i++;
}

int	extract_f_c(t_param *world, char **split)
{
	if (len_array_2d(split) == 2)
	{
		if (ft_strsame(split[0], "F"))
		{
			world->floor_color = to_hex_int(split[1], world);
			world->counter[4] += 1;
		}
		else if (ft_strsame(split[0], "C"))
		{
			world->ceiling_color = to_hex_int(split[1], world);
			world->counter[5] += 1;
		}
	}
	if (world->floor_color == -1 || world->ceiling_color == -1)
		return (-1);
	else
		return (0);
}

void	extract_sand_rose(t_param *world, char **split)
{
	if (len_array_2d(split) == 2)
	{
		if (ft_strsame(split[0], "NO") && !world->no)
			world->no = ft_strdup(split[1]);
		if (ft_strsame(split[0], "NO"))
			world->counter[0] += 1;
		if (ft_strsame(split[0], "SO") && !world->so)
			world->so = ft_strdup(split[1]);
		if (ft_strsame(split[0], "SO"))
			world->counter[1] += 1;
		if (ft_strsame(split[0], "WE") && !world->we)
			world->we = ft_strdup(split[1]);
		if (ft_strsame(split[0], "WE"))
			world->counter[2] += 1;
		if (ft_strsame(split[0], "EA") && !world->ea)
			world->ea = ft_strdup(split[1]);
		if (ft_strsame(split[0], "EA"))
			world->counter[3] += 1;
	}
}

void	loop_in_file(t_param *world, int fd)
{
	char	*holder;
	char	**split;

	split = NULL;
	holder = get_next_line(fd);
	while (holder)
	{
		map_data_check(world, holder);
		split = ft_split(holder, ' ');
		extract_sand_rose(world, split);
		if (extract_f_c(world, split) == -1)
		{
			free_split(split);
			error_exit("Invalid Floor or ceiling color", world, holder, fd);
		}
		find_map_start(world, holder);
		free_split(split);
		free(holder);
		holder = get_next_line(fd);
	}
	free(holder);
	extract_map(world);
}

void	extract_file( t_param *world, int fd)
{
	int	i;

	world->counter = malloc(sizeof(int) * 6);
	if (!world->counter)
		error_exit("Counter malloc error", world, NULL, -1);
	i = 0;
	while (i < 6)
		world->counter[i++] = 0;
	loop_in_file(world, fd);
}
