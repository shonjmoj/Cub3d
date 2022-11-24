/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:36:05 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/24 16:18:46 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	get_player(char **map, int length)
{
	int	i;
	int	j;
	int	p;

	p = 0;
	i = 1;
	while (i < length)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E')
			{
				g_player = map[i][j];
				p++;
			}
			j++;
		}
		i++;
	}
	if (p != 1)
		return (-1);
	return (g_player);
}

int	vertical_check(char **map)
{
	int	i;
	int	j;

	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '0' && \
				((map[i - 1][j] != '1' && map[i - 1][j] != '0' && \
				map[i - 1][j] != g_player) || (map[i + 1][j] != '1' && \
				map[i + 1][j] != '0' && map[i + 1][j] != g_player))) || \
				(map[i][j] == g_player && ((map[i - 1][j] != '1' && \
				map[i - 1][j] != '0') || (map[i + 1][j] != '1' && \
				map[i + 1][j] != '0'))))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_characters(t_map *map)
{
	int	i;
	int	len;

	i = 1;
	len = tab2d_length(map->map) - 1;
	g_player = get_player(map->map, len);
	if (g_player == -1 || !valid_top_bottom_walls(map->map) || \
		!valid_map_body(map->map) || !vertical_check(map->map))
		return (0);
	return (1);
}

int	valid_map_body(char **map)
{
	int	len;
	int	i;
	int	j;

	i = 1;
	len = tab2d_length(map) - 2;
	j = 0;
	while (i <= len)
	{
		if (ft_strlen(map[i]) < ft_strlen(map[i + 1]))
			if (!is_border(ft_strlen(map[i]), map[i + 1]))
				return (0);
		if (!valid_floor(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	tab2d_length(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i])
			i++;
	}
	return (i);
}