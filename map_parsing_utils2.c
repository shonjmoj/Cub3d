/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:33:47 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/24 16:15:38 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_top_bottom_walls(char **map)
{
	int	len;
	int	i;

	i = 0;
	len = tab2d_length(map) - 1;
	while (map[0][i])
	{
		if ((map[0][i] != ' ' && map[0][i] != '1') || \
			(map[0][i] == ' ' && (map[1][i] == '0' || \
			map[1][i] == g_player)))
			return (0);
		i++;
	}
	i = 0;
	while (map[len][i])
	{	
		if ((map[len][i] != ' ' && map[len][i] != '1') || \
			(map[len][i] == ' ' && (map[len - 1][i] == '0' || \
			map[len - 1][i] == g_player)))
			return (0);
		i++;
	}
	return (1);
}

int	valid_floor(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(line) - 1;
	while (line[i] == ' ')
		i++;
	while (line[j] == ' ')
		j--;
	if (line[i] != '1' || line[j] != '1')
		return (0);
	while (i <= j)
	{
		if ((line[i] == '0' && ((line[i + 1] != '1' && \
			line[i + 1] != g_player && line [i + 1] != '0') || \
			(line[i - 1] != '1' && \
			line[i - 1] != g_player && line [i - 1] != '0'))) || \
			(line[i] == g_player && ((line[i + 1] != '1' && \
			line[i + 1] != '0') || (line[i - 1] != '1' && \
			line[i - 1] != '0'))))
			return (0);
		i++;
	}
	return (1);
}

int	is_border(size_t index, char *line)
{
	while (index < ft_strlen(line))
	{
		if (line[index] == '0')
			return (0);
		index++;
	}
	return (1);
}
