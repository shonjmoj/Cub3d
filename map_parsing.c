/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:09:31 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/16 16:15:03 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_map(char *line, int fd, t_map *map)
{
	while (1)
	{
		if ((ft_strchr(line, ' ') && ft_strchr(line, '1')))
			break;
		line = get_next_line(fd);
		// printf("%s", line);
		if (!line)
			break;
	}
	while (1)
	{
		if (!line)
			break ;
		if (line[0] == '\n')
			return (0);
		if (line[0] != '\n') {
			map->map = tab_join(map->map, line);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!map->map || !valid_walls(map->map) || check_map_characters(map->map) != 1)
		return (0);
	int i = 0;
	while (map->map[i])
		printf("%s\n", map->map[i++]);
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
			if (!get_textures(line, map))
				return (return_and_free(line), 0);
		if (completed_config(map))
			if (!valid_map(line, fd, map))
				return (return_and_free(line), 0);
		free(line);
	}
	return (return_and_free(line), 1);
}
