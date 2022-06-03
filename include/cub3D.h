/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:30:20 by npinheir          #+#    #+#             */
/*   Updated: 2022/06/03 16:03:56 by npinheir         ###   ########.fr       */
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

typedef enum e_bool{
	FALSE = 0,
	TRUE = 1,
}t_bool;

# define SIZE 64
# define NBRAY 60
# define SCREEN_HEIGHT 900
# define SCREEN_WIDTH 900
# define NOSE 20

typedef struct s_mapD
{
	char			*path;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				floor;
	int				ceiling;
	int				*counter;
	char			**map;
	unsigned int	map_len;
	unsigned int	map_hight;
	int				x_pos;
	int				y_pos;
	char			p_ori;
	
}	t_mapD;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_param{
	int				p_x_pos;
	int				p_y_pos;
	int				p_orient;
	unsigned int	p_x_mid;
	unsigned int	p_y_mid;
	unsigned int	p_map_x;
	unsigned int	p_map_y;
	unsigned int	p_size;
	double			p_front;
	char			**map;
	unsigned int	map_height;
	unsigned int	map_width;
	void			*video;
	void			*window;
	t_data			*img;
	int				screen_height;
	int				screen_width;
	int				floor_color;
	int				ceiling_color;
	int				wall_color;
	t_mapD			*map_data;
}t_param;

// Cub File
t_mapD	cub_file_check_and_fill(char *path);
int		extention_check(const char *path);
void	extract_file(t_mapD *map, int fd);

// File Extractors
void	extract_sand_rose(t_mapD *map, char **split);
void	extract_f_c(t_mapD *map, char **split);
void	extract_map(t_mapD *map);
void	map_data_check(t_mapD *map, const char *holder);
int		valid_map_line(const char *holder);

// Errors
void	error_exit(const char *message);

// Utils
int		to_hex_int(const char *str);
size_t	len_array_2d(char **split);
void	bresenham_1(int x0, int y0, int x1, int y1, t_param * world);


// Graphic
void	init_window(t_param *world);
int		draw_view(t_param *world);
void	pixel_to_image(t_data *img, int x, int y, int color);
void	draw_col(t_param *world, double dist, double offset);
int		create_trgb(int t, int r, int g, int b);
double	calcul_dist_till_wall(t_param *world, double orientation);
double	next_vert_wall(t_param *world, double orientation);
double	next_hor_wall(t_param *world, double orientation);
double	degre_to_radiant(double degre);
int		check_left_wall(int x, int y, t_param *world);
int		check_right_wall(int x, int y, t_param *world);
int		check_up_wall(int x, int y, t_param *world);
int		check_down_wall(int x, int y, t_param *world);

// Minimap
void	draw_minimap(t_param *world);
void	draw_player_nose(t_param *world);

//key 
int		keyboard(int keycode, t_param *world);

//exit
void	exit_cub3d(t_param *world);

//move
void	move_forward(t_param *world);

#endif