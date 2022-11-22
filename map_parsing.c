/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:09:31 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/22 10:36:58 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**tab_join(char **arr, char *str)
{
	char	**tab;
	int		i;

	tab = malloc(sizeof(char *) * (tab2d_length(arr) + 2));
	i = 0;
	if (arr != NULL)
	{
		while (arr[i] != NULL)
		{
				tab[i] = ft_strtrim(arr[i], "\n");
			i++;
		}
	}
	tab[i++] = ft_strtrim(str, "\n");
	tab[i] = NULL;
	if (arr)
		free_2d(arr);
	return (tab);
}



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
			while ((line = get_next_line(fd)))
			{
				if (!line)
					break;
				map->map = tab_join(map->map, line);
				free(line);
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