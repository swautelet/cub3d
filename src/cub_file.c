/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:34:50 by npinheir          #+#    #+#             */
/*   Updated: 2022/05/31 22:08:49 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int		extention_check(const char *path)
{
	/*	Checks if the extension (.cub) is valid.	*/
	char	*extention;
	size_t	len;

	len = ft_strlen(path);
	if (len <= 3)
		return (1);
	extention = ft_substr(path, len - 4, len);
	if (!ft_strsame(".cub", extention))
		return (1);
	free(extention);
	return (0);
}

int		counter_check(int *counter)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (counter[i++] != 1)
			return (1);
	}
	return (0);
}

void	extract_file(t_mapD *map, int fd)
{
	char	*holder;
	char	**split;
	int		i;

	i = 0;
	map->counter = malloc(sizeof(int) * 6);
	if (!map->counter)
		error_exit("Malloc error ");
	while (i < 6)
		map->counter[i++] = 0;

	while (get_next_line(fd, &holder))
	{
		split = ft_split(holder, ' ');
		extract_sand_rose(map, split);
		extract_f_c(map, split);
	}
	if (counter_check(map->counter))
		error_exit("Corrupted .cub file ");
	//extract_map(map);
}


t_mapD	cub_file_check_and_fill(char *path)
{
	/*	Handels the entire extraction based on the the .cub file path.	*/
	int		fd;
	t_mapD	map;

	map.path = path;
	if ((fd = open(path, O_DIRECTORY)) != -1)
		error_exit("This is a directory ");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("Failed to open the .cub file ");
	if (extention_check(path))
		error_exit("Not a .cub file ");
	extract_file(&map, fd);
	return (map);
}
