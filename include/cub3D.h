/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:30:20 by npinheir          #+#    #+#             */
/*   Updated: 2022/05/31 22:00:53 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>

typedef struct s_mapD
{
	char	*path;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;
	int		*counter;
	char	**map;
}	t_mapD;

// Cub File
t_mapD	cub_file_check_and_fill(char *path);
int		extention_check(const char *path);
void	extract_file(t_mapD *map, int fd);

// File Extractors
void	extract_sand_rose(t_mapD *map, char **split);
void	extract_f_c(t_mapD *map, char **split);
void	extract_map(t_mapD *map);

// Errors
void	error_exit(const char *message);

// Utils
int		to_hex_int(const char *str);
size_t	len_array_2d(char **split);

#endif