/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:22:12 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/08 14:22:16 by npinheir         ###   ########.fr       */
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

# define SIZE 64
# define NBRAY 60
# define SCREEN_HEIGHT 900
# define SCREEN_WIDTH 900
# define NOSE 20

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1,
}	t_bool;

typedef	struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_param
{
	int				px_x_pos;	// Player x position in pixels
	int				px_y_pos;	// Player y position in pixels
	int				orient;		// Player orientation
	int				map_x_pos;	// Player x position in the map
	int				map_y_pos;	// Player y position in the map
	int				player_size;	// Length of side of square representing player
	double			player_front;	// The ray laaunched just in front of the player
	char			**map;	// Actual map
	unsigned int	map_height;	// Amount of lines in the map
	unsigned int	map_width;	// Amount of columns in the map
	void			*video;	// MLX instance
	void			*window;	// MLX window
	t_data			*img;	// MLX image
	void			*clean;	// Something clean ??
	int				floor_color;	
	int				ceiling_color;
	int				wall_color;
	char			*path;	// Path to the .cub file
	char			*no;	// Path to textures
	char			*so;
	char			*we;
	char			*ea;
	int				*counter;	// Helps doing parsing
}	t_param;

// Drawing
void	init_window(t_param *world);
int		draw_view(t_param *world);
void	draw_col(t_param *world, double dist, double offset);

// Hooks
int		keyboard(int keycode, t_param *world);
void	move_forward(t_param *world);

// Minimap
void	draw_minimap(t_param *world);
void	paint_square_map(unsigned int x, unsigned int y, unsigned int square_length, t_param *world);
void	draw_player_nose(t_param *world);

// Distance
double	calcul_dist_till_wall(t_param *world, double orientation);
double	next_vert_wall(t_param *world, double orientation);
double	next_hor_wall(t_param *world, double orientation);

// Walls
int	check_left_wall(int x, int y, t_param *world);
int	check_right_wall(int x, int y, t_param *world);
int	check_up_wall(int y, int x, t_param *world);
int	check_down_wall(int y, int x, t_param *world);

// .cub file
void	cub_file_check_and_fill(t_param *world, char *path);
int		extention_check(const char *path);
void	extract_file( t_param *world, int fd);

// Map extractor
void	map_data_check(t_param *world, const char *holder);
int		valid_map_line(const char *holder);
void	extract_map(t_param *world);
void	get_player_position(t_param *world);

// File extractor
void	extract_sand_rose(t_param *world, char **split);
void	extract_f_c(t_param *world, char **split);

// Utils
int		to_hex_int(const char *str, t_param *world);
size_t	len_array_2d(char **split);
int		create_trgb(int t, int r, int g, int b);
void	pixel_to_image(t_data *img, int x, int y, int color);
void	exit_cub3d(t_param *world);
double	degre_to_radiant(double degre);
void	bresenham(int x0, int y0, int x1, int y1, t_param * world);

// Errors
void	error_exit(const char *message, t_param *world);



#endif