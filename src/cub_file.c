/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:11:38 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/17 01:48:10 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	extention_check(const char *path)
{
	char	*extention;
	size_t	len;

	len = ft_strlen(path);
	if (len <= 3)
		return (1);
	extention = ft_substr(path, len - 4, len);
	if (!ft_strsame(".cub", extention))
	{
		free(extention);
		return (1);
	}
	free(extention);
	return (0);
}

void	cub_file_check_and_fill(t_param *world, char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd != -1)
		error_exit("This is a directory", world, NULL, -1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("Failed to open the .cub file", world, NULL, -1);
	if (extention_check(path))
		error_exit("Not a .cub file", world, NULL, fd);
	world->path = ft_strdup(path);
	extract_file(world, fd);
	close(fd);
}
