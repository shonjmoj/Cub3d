/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:36:05 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/16 13:12:17 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_map_characters(char **map)
{
	int	i;
	int	len;
	int	j;
	int p;

	p = 0;
	i = 1;
	len = tab2d_length(map) - 1;
	while (i < len)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (map[i + 1][j] == ' ' || map[i - 1][j] == ' ') 
					return (0);
				p++;
			}
			if ((map[i][j] == '0' && map[i + 1][j] == ' ') || \
				(map[i][j] == ' ' && map[i + 1][j] == '0'))
				return (0);
			j++;
		}
		i++;
	}
	return (p);	
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
	free_2d(arr);
	return (tab);
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
	while (i != j)
	{
		if ((line[i] == '0' && line[i + 1] == ' ') || \
			(line[i] == '0' && line[i - 1] == ' '))
			return (0);
		i++;
	}
	return (1);
}

int	valid_walls(char **map)
{
	int	len;
	int	i;

	i = 0;
	len = tab2d_length(map) - 1;
	while (map[0][i])
	{
		if (map[0][i] != ' ' && map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[len][i])
	{
		if (map[len][i] != ' ' && map[len][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (++i < len)
	{
		if (!check_all_walls(map[i]))
			return (0);
	}
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

// char *resize_line(char *line, size_t size)
// {
// 	size_t	i;
// 	char	*newline;

// 	newline = NULL;
// 	i = 0;
// 	newline = malloc(sizeof(char) * size + 1);
// 	while (line[i])
// 	{
// 		newline[i] = line[i];
// 		i++;	
// 	}
// 	if (line[i] == '\0')
// 		while (i < size)
// 		{
// 			newline[i] = ' ';
// 			i++;
// 		}
// 	newline[i] = '\0';
// 	return (newline);
// }

// void resize_map(char **map, size_t size)
// {
// 	int		i;
// 	char	*newline;

// 	newline = NULL;
// 	i = 0;
// 	while (map[i])
// 	{
// 		newline = resize_line(map[i], size);
// 		free(map[i]);
// 		map[i] = ft_strtrim(newline, "\n");
// 		free(newline);
// 		i++;
// 	}
// }