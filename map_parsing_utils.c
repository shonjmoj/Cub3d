/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:36:05 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/19 18:46:02 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int valid_floor(char **map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == ' ' && (map[i][j + 1] != '1' || \
// 				map[i][j + 1] != ' ' || map[i][j - 1] != '1' || \
// 				map[i][j - 1] != ' '))			
// 			j++;
// 		}
// 		i++;
// 	}
// }

char get_player(char **map, int length)
{
	int	i;
	int	j;
	int p;

	p = 0;
	i = 1;
	while(i < length)
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E')
				{
					player = map[i][j];
					p++;
				}
			j++;
		}
		i++;
	}
	if (p != 1)
		return (-1);
	return (player);
}

int	check_map_characters(t_map *map)
{
	int	i;
	int	len;

	i = 1;
	len = tab2d_length(map->map) - 1;
	player = get_player(map->map, len);
	if (player == -1 || !valid_walls(map->map))
		return (0);
	return (1);	
}

int	check_walls(char *line)
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
		if (((line[i] == ' ' && line[i + 1] == '0') || \
			(line[i] == '0' && line[i + 1] == ' ')))
			return (0);
		i++;
	}
	return (1);
}

int	check_all_walls(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(line) - 1;
	if (!check_walls(line))
		return (0);
	while (line[i] == ' ')
		i++;
	while (line[j] == ' ')
		j--;
	while (i <= j)
	{
		if ((line[i] == '0' && line[i + 1] == ' ') || \
			(line[i] == '0' && line[i - 1] == ' '))
			return (0);
		i++;
	}
	return (1);
}

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
	if (ft_strncmp(str, "\n", ft_strlen(str)))
		tab[i++] = ft_strtrim(str, "\n");
	tab[i] = NULL;
	if (arr)
		free_2d(arr);
	return (tab);
}


int	valid_walls(char **map)
{
	int	len;
	int	i;

	i = -1;
	len = tab2d_length(map) - 1;
	while (map[0][i++])
		if ((map[0][i] != ' ' && map[0][i] != '1') || \
			(map[0][i] == ' ' && map[1][i] == '0') || \
			(map[0][i] == ' ' && map[1][i] == player)) {
				return (0);
			}
	i = 0;
	while (map[len][i])
	{	
		if ((map[len][i] != ' ' && map[len][i] != '1') || \
			(map[len][i] == ' ' && map[len - 1][i] == '0') || \
			(map[len][i] == ' ' && map[len - 1][i] == player)) 
				return (0);
		i++;
	}
	i = 0;
	while (i++ < len)
		if (!check_all_walls(map[i]))
			return (0);
	return (1);
}

// int	get_map_width(t_map *map)
// {
// 	int		i;
// 	size_t	w;

// 	i = 0;
// 	w = ft_strlen(map->map[i]);
// 	if (map->map)
// 	{
// 		while (map->map[i])
// 		{
// 			if (ft_strlen(map->map[i]) > w)
// 				w = ft_strlen(map->map[i]);
// 			i++;
// 		}
// 	}
// 	return (w);
// }