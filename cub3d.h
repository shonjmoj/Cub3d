/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:08:24 by elounejj          #+#    #+#             */
/*   Updated: 2022/12/27 19:58:52 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>
#include <stdbool.h>
#include "Libft/libft.h"

#define BUFFER_SIZE 1000
#define W 10
#define N 20
#define S 30
#define E 40
#define TILE 16
#define W_WIDTH 1080
#define W_HEIGHT 720
#define FOFV 1.0471975512

char g_player;

typedef struct s_rgb
{
	int c_red;
	int f_red;
	int c_green;
	int f_green;
	int c_blue;
	int f_blue;
} t_rgb;

typedef struct s_map
{
	char *no;
	char *so;
	char *we;
	char *ea;
	char *f_c;
	void *img;
	int		**img_data;
	char **map;
	t_rgb colors;
	int x_pos;
	int y_pos;
	int height[4];
	int width[4];

} t_map;

typedef struct s_vector
{
	double x;
	double y;
	bool is_it_vertical;
} t_vector;

typedef struct s_calc
{
	int h;
	int v;
	double dis_h;
	double dis_v;
} t_calc;

typedef struct s_image
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_image;

typedef struct s_player
{
	t_vector posi;
	double x;
	double y;
	double radius;
	double turndirection;
	double waldirection;
	double left_rightdirection;
	double rotationangle;
	double movespeed;
	double rotationspeed;
} t_player;

typedef struct s_data
{
	void *mlx;
	void *mlx_win;
	char *value;
	int **map_int;
	int map_x;
	int map_y;
	t_image img;
	t_player player;
	t_vector mouse;
	bool is_clicked;
	t_vector posi_player;
	double alpha;
	t_vector rays[W_WIDTH];
	t_map map_element;
	double dis_rays[W_WIDTH];
	t_rgb color;
	int id;
	double face;
	// t_fr_elem	var;
} t_data;

char *get_next_line(int fd);
int check_map_ext(char *filname);
int valid_side(char *line);
void print_error(const char *error);
char *ft_free(char **adr_str);
int return_and_free(void *ptr);
int get_textures(char *line, t_map *map);
void init_map(t_map *map);
void free_2d(void **arr);
int tab2d_length(char **arr);
int completed_config(t_map *map);
void clear_map(t_map *map);
int get_colors(t_map *map, char *type);
int valid_parsing(t_map *map, int fd);
int check_all_walls(char *line);
char **tab_join(char **arr, char *str);
int valid_top_bottom_walls(char **map);
int is_border(size_t index, char *line);
int check_map_characters(t_map *map);
int valid_floor(char *line);
int valid_map_body(char **map);
void set_player_pos(t_map *data);
void load_textures(t_data *data);
int	key_hook(int keycode, t_data *data);
int	key_release(int keycode, t_data *data);
int	cross_x(t_data *data);
int	ft_draw(t_data *data);
void free_all(t_data *data);
t_vector	ft_len_of_line(t_data data);
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	ft_draw_field_of_view(t_data *data);
void	ft_raycasting_calc(t_data *data);
int		wall_check(t_data *data, double newx, double newy);
int		its_a_wall(t_data *data, int x, int y);
int		ft_rendering_wall(t_data *data);
t_vector	ft_check_calc(t_data data, t_calc calc, t_vector a_h, t_vector a_v);
void	ft_horizontal_calc(t_data data, t_vector	*step_h, t_vector	*a_h);
void	ft_vertical_calc(t_data data, t_vector	*step_v, t_vector	*a_v);
int	ft_check_vertical(t_data data, t_vector	*step_v, t_vector	*a_v, int *v);
int	ft_check_horizontal(t_data data, t_vector *step_h, t_vector *a_h, int *h);
void	ft_draw_wall(t_data *data, int start, int len, double wall);
void	*ft_malloc(int size);
int	long_line(char **str);
int	**ft_to_int(char **map);

#endif