/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:09:31 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/13 17:30:35 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_map(char *line, int fd)
{
	while (1)
	{
		line = get_next_line(fd);
		if (!line || ft_strncmp(line, "\n", ft_strlen(line)))
			break ;
		free(line);
	}
	while (1)
	{
		if (!line)
			break ;
		if (line[0] == '\n')
			return (return_and_free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	valid_parsing(t_map *map, int fd)
{
	char	*line;

	line = NULL;
	init_map(map);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n' && !completed_config(map))
			if (get_textures(line, map) == 0)
				return (return_and_free(line), 0);
		if (completed_config(map))
			if (!valid_map(line, fd))
				return (return_and_free(line), 0);
		free(line);
	}
	return (return_and_free(line), 1);
}
