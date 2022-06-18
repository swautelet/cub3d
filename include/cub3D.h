/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:54:35 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 11:36:06 by npinheir         ###   ########.fr       */
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
# include <limits.h>
# include <float.h>

# define ANGLEVISION 60
# define ECAR 0.05
# define SCREEN_HEIGHT 600

typedef enum e_dir{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	DO = 4,
	KE = 5,
	EN = 6,
}	t_dir;

typedef	struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		y_size;
	int		x_size;
}	t_img;

typedef struct s_param
{
	double			px_x_pos;
	double			px_y_pos;
	int				map_x_pos;
	int				map_y_pos;
	int				orient;

	char			**map;	// Malloc OK
	unsigned int	map_height;
	unsigned int	map_width;
	unsigned int	map_start;

	char			*path; // Malloc OK
	char			*no; // Malloc OK
	char			*so; // Malloc OK
	char			*we; // Malloc OK
	char			*ea; // Malloc  OK
	int				floor_color;
	int				ceiling_color;
	unsigned int	amount_key;

	int				*counter; // Malloc OK

	void			*instance;
	void			*window;
	t_img			*img;	// Malloc OK
	t_img			*texture; // Malloc OK
	t_img			*calque;	// Malloc OK

	int				nb_ray;
}	t_param;

// -- Let's Cube --
void	lets_cub(t_param *world);
int		draw_view(t_param *world);
int		keyboard_press(int keycode, t_param *world);
int		keyboard_release(int keycode, t_param *world);

// -- Cube File --
void	cub_file_check_and_fill(t_param *world, char *path);
int		extention_check(const char *path);

// -- Player --
void	get_player_position(t_param *world);
void	get_player_orientation(t_param *world, char tag);

// -- Extract Map --
void	extract_map(t_param *world);
void	process_map(t_param *world, int *fd, char **holder);
void	fill_spaces(t_param *world);
void	get_amount_key(t_param *world);

// -- Extract File --
void	extract_file( t_param *world, int fd);
void	loop_in_file(t_param *world, int fd);
void	extract_sand_rose(t_param *world, char **split);
void	extract_f_c(t_param *world, char **split);
void	find_map_start(t_param *world, const char *holder);

// -- Map Check --
void	map_data_check(t_param *world, const char *holder);
int		valid_map_line(const char *holder);
void	fill_spaces(t_param *world);
void	last_map_check(t_param *world);
void	check_map_end(t_param *world, size_t i);

// -- Initialization --
void	init_world(t_param *world);
void	init_mlx(t_param *world);
void	init_textures(t_param *world);
void	set_textures(t_param *world);

// -- Free --
void	free_world(t_param *world);
void	free_split(char **split);

// -- Errors --
void	error_exit(char *message, t_param *world, char *str_tr_free,
	int fd_to_close);
int		succes_exit(t_param *world);
void	clean_close_mlx(t_param *world);

// -- Utils --
size_t	len_array_2d(char **split);
int		to_hex_int(const char *str, t_param *world);
void	check_max_int(long long int check, t_param *world);
int		counter_check(int *counter);
void	skip_non_map(t_param *world, int *fd, char **holder);

// -- Utils 2 --
char	*space_string(size_t len, t_param *world);

#endif
