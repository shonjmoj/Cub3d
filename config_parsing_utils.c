/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parsing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:23:55 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/15 11:59:23 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_side(char *line)
{
	if ((line[0] == 'N' && line[1] == 'O') || \
		(line[0] == 'S' && line[1] == 'O') || \
		(line[0] == 'W' && line[1] == 'E') || \
		(line[0] == 'E' && line[1] == 'A') || \
		(line[0] == 'F' || line[0] == 'C') || \
		line[0] == '\n')
		return (1);
	return (0);
}

void	init_map(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f_c = NULL;
	map->map = NULL;
	map->colors.c_red = -1;
	map->colors.c_green = -1;
	map->colors.c_blue = -1;
	map->colors.f_red = -1;
	map->colors.f_green = -1;
	map->colors.f_blue = -1;
}

void	clear_map(t_map *map)
{
	if (map->so)
		free(map->so);
	if (map->no)
		free(map->no);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	if (map->f_c)
		free(map->f_c);
	if (map->map)
		free_2d(map->map);
}

int	completed_config(t_map *map)
{
	if (!map->no || !map->so || !map->we || !map->ea || \
		map->colors.c_red == -1 || map->colors.c_green == -1 || \
		map->colors.c_blue == -1 || map->colors.f_red == -1 || \
		map->colors.f_green == -1 || map->colors.f_blue == -1)
		return (0);
	return (1);
}	

int	valid_texture(char *texture)
{
	int		fd;
	int		len;
	char	*tmp;

	tmp = NULL;
	tmp = ft_strtrim(texture, " \n");
	len = ft_strlen(tmp) - 1;
	if (tmp[len] != 'm' || tmp[len - 1] != 'p' || tmp[len - 2] != 'x'
		|| tmp[len - 3] != '.')
	{
		free(tmp);
		return (0);
	}
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int	get_textures(char *line, t_map *map)
{
	char	**texture;

	texture = ft_split(line, ' ');
	if ((tab2d_length(texture) == 3 && \
		texture[2][0] != '\n') || !valid_side(texture[0]) || \
		(ft_strncmp(texture[0], "F", ft_strlen(texture[0])) && \
		ft_strncmp(texture[0], "C", ft_strlen(texture[0])) && \
		!valid_texture(texture[1])))
		return (return_and_free(texture), 0);
	if (!ft_strncmp(texture[0], "NO", ft_strlen(texture[0])))
		map->no = ft_strtrim(texture[1], "\n");
	else if (!ft_strncmp(texture[0], "SO", ft_strlen(texture[0])))
		map->so = ft_strtrim(texture[1], "\n");
	else if (!ft_strncmp(texture[0], "WE", ft_strlen(texture[0])))
		map->we = ft_strtrim(texture[1], "\n");
	else if (!ft_strncmp(texture[0], "EA", ft_strlen(texture[0])))
		map->ea = ft_strtrim(texture[1], "\n");
	else
	{
		map->f_c = ft_strtrim(texture[1], "\n");
		get_textures2(map, texture[0]);
	}
	free_2d(texture);
	return (1);
}
