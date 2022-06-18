/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swautele <swautele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:54:35 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/18 12:35:33 by swautele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define ANGLEVISION 60
# define ECAR 0.025
# define SCREEN_HEIGHT 1200
# define MOVE 0.1
# define ROTATE 5

typedef struct s_key{
	int				x;
	int				y;
	int				key_size;
	int				mid;
	double			x_texture;
	double			y_texture;
	unsigned int	color;
}	t_key;

typedef enum e_dir
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	DO = 4,
	KE = 5,
	EN = 6,
}	t_dir;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		y_size;
	int		x_size;
}	t_img;

typedef struct s_fuck
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_fuck;

typedef struct s_bres
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bres;

typedef struct s_check{
	int	new_x;
	int	new_y;
}	t_check;

typedef struct s_param
{
	double			px_x_pos;
	double			px_y_pos;
	int				map_x_pos;
	int				map_y_pos;
	int				orient;
	double			limit;
	double			player_front;
	double			player_back;
	double			player_left;
	double			player_right;
	double			x_wallkey;
	double			dist_key;
	t_bool			keyfound;
	int				flag_wall;
	int				half_screen;
	int				mid;
	t_bool			flag_rotateleft;
	t_bool			flag_rotateright;
	t_bool			flag_front;
	t_bool			flag_left;
	t_bool			flag_right;
	t_bool			flag_back;
	t_bool			key_picked;
	t_bool			flag_first_ray;
	unsigned int	square_length;
	int				player_size;
	char			**map;
	unsigned int	map_height;
	unsigned int	map_width;
	unsigned int	map_start;
	char			*path;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				floor_color;
	int				ceiling_color;
	unsigned int	amount_key;
	int				*counter;
	void			*instance;
	void			*window;
	t_img			*img;
	t_img			*texture;
	t_img			*calque;
	int				nb_ray;
	int				offset_anim;
	t_bool			flag_anim;
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

// distance -- 
double	next_vert_wall(t_param *world, double orientation,
			double *vert_x_wall, int *sub_door_vert);
double	next_hor_wall(t_param *world, double orientation,
			double *hor_x_wall, int *sub_door_hor);

// graphic -- 
int		get_color_from_img(t_img *img, int x, int y);
void	draw_key(t_param *world, double offset, double dist);
void	draw_col(t_param *world, double dist, double offset, double x_wall);
double	calcul_dist_till_wall(t_param *world, double orientation,
			double *x_wall);
void	colorise(t_img *img, int x, int y);
void	draw_minimap(t_param *world);
void	paint_square_map(unsigned int x, unsigned int y, t_param *world);
void	draw_player_nose(t_param *world);

// check wall -- 
int		check_left_wall(double y, double x, t_param *world);
int		check_right_wall(double y, double x, t_param *world);
int		check_up_wall(double y, double x, t_param *world);
int		check_down_wall(double y, double x, t_param *world);
void	open_door(t_param *world);

// move -- 
int		keyboard(t_param *world);
void	move_forward(t_param *world);
void	move_left(t_param *world);
void	move_right(t_param *world);
void	move_back(t_param *world);

// -- Extract Map --
void	extract_map(t_param *world);
void	process_map(t_param *world, int *fd, char **holder);
void	fill_spaces(t_param *world);
void	get_amount_key(t_param *world);

// -- Extract File --
void	extract_file(t_param *world, int fd);
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
void	init_second_part(t_param *world);

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
void	bresenham(t_fuck d, t_param *world);

// -- Utils 2 --
char	*space_string(size_t len, t_param *world);
int		create_trgb(int t, int r, int g, int b);
void	pixel_to_image(t_img *img, int x, int y, int color);
double	degre_to_radiant(double degre);

#endif
