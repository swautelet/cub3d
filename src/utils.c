/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:57:10 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 01:49:07 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	skip_non_map(t_param *world, int *fd, char **holder)
{
	size_t	i;

	i = 0;
	while (i < world->map_start - 1)
	{
		get_next_line(*fd, holder);
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
	if (check > 2147483647 || check < 0)
		error_exit("Corrupted .cub file ", world, NULL, -1);
}

int	to_hex_int(const char *str, t_param *world)
{
	char			**split;
	long long int	r;
	long long int	g;
	long long int	b;

	split = ft_split(str, ',');
	if (!(ft_isstrdigit(split[0]) && ft_isstrdigit(split[1])
			&& ft_isstrdigit(split[2])))
		error_exit("Corrupted .cub file", world, NULL, -1);
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

	res = 0;
	while (split[res])
		res++;
	return (res);
}
