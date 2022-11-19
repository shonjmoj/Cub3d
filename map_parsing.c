/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:09:31 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/19 18:51:22 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_parsing(t_map *map, int fd)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (line[0] != '\n' || !completed_config(map))
			get_textures(line, map);
		if (completed_config(map))
		{
			free(line);
			line = get_next_line(fd);
			while(1)
			{
				if (!line)
					break;
				map->map = tab_join(map->map, line);
				free(line);
				line = get_next_line(fd);
			}
		}
		free(line);
	}
	if (!completed_config(map) || !check_map_characters(map))
		return (0);
	int i = 0;
	if (map->map)
		while (map->map[i])
			printf("%s\n", map->map[i++]);
	return (return_and_free(line), 1);
}