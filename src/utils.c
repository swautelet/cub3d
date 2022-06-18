/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:43:08 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 15:43:14 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	skip_non_map(t_param *world, int *fd, char **holder)
{
	int	i;

	i = 0;
	while (i < world->map_start)
	{
		*holder = get_next_line(*fd);
		free(*holder);
		i++;
	}
}

int	counter_check(int *counter)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (counter[i] == 0)
			return (1);
		else if (counter[i] > 1)
			return (2);
		i++;
	}
	return (0);
}

void	check_max_int(long long int check, t_param *world)
{
	if (check > 255 || check < 0)
		error_exit("Invalid Floor or ceiling color ", world, NULL, -1);
}

int	to_hex_int(const char *str, t_param *world)
{
	char			**split;
	long long int	r;
	long long int	g;
	long long int	b;

	if (str[ft_strlen(str) - 1] == ',')
		return (-1);
	split = ft_split(str, ',');
	if (!(ft_isstrdigit(split[0]) && ft_isstrdigit(split[1])
			&& ft_isstrdigit(split[2])) || split[3])
	{
		free_split(split);
		return (-1);
	}
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	check_max_int(r, world);
	check_max_int(g, world);
	check_max_int(b, world);
	free_split(split);
	return (0 << 24 | r << 16 | g << 8 | b);
}

size_t	len_array_2d(char **split)
{
	size_t	res;

	if (!split)
		return (0);
	res = 0;
	while (split[res])
		res++;
	return (res);
}
