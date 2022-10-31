/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:08:24 by elounejj          #+#    #+#             */
/*   Updated: 2022/10/31 10:54:14 by elounejj         ###   ########.fr       */
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

char	*get_next_line(int fd);
int		check_map_ext(char *filname);
int		valid_side(char *line);
void	print_error(const char *error);
char	*ft_free(char **adr_str);
int		valid_texture(char *line);
int     return_and_free(void *ptr);

#endif