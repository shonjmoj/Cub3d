/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:08:24 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/12 11:46:03 by elounejj         ###   ########.fr       */
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

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
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
int		completed_textures(t_map *map);

#endif