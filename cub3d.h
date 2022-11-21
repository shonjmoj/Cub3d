/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:08:24 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/21 09:42:20 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "Libft/libft.h"

# define BUFFER_SIZE 1000

char player;

typedef struct s_rgb
{
	int	c_red;
	int	f_red;
	int	c_green;
	int	f_green;
	int	c_blue;
	int	f_blue;
}			t_rgb;

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f_c;
	t_rgb	colors;
	char	**map;

}			t_map;


char	*get_next_line(int fd);
int		check_map_ext(char *filname);
int		valid_side(char *line);
void	print_error(const char *error);
char	*ft_free(char **adr_str);
int		return_and_free(void *ptr);
int		get_textures(char *line, t_map *map);
void	init_map(t_map *map);
void	free_2d(char **arr);
int		tab2d_length(char **arr);
int		completed_config(t_map *map);
void	clear_map(t_map *map);
int		free_all_2dtabs(void *ptr1, void *ptr2);
int		get_colors(t_map *map, char *type);
int		valid_parsing(t_map *map, int fd);
int		check_all_walls(char *line);
char	**tab_join(char **arr, char *str);
int		valid_top_bottom_walls(char **map);
int		is_wall(char *line);
int		get_map_width(t_map *map);
char	*resize_line(char *line, size_t size);
void	resize_map(char **map, size_t size);
int		check_map_characters(t_map *map);
int		valid_map_body(char **map);

#endif