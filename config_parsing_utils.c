/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parsing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:23:55 by elounejj          #+#    #+#             */
/*   Updated: 2022/12/27 15:58:40 by elounejj         ###   ########.fr       */
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

int	get_textures2(char **texture, t_map *map)
{
	if (!ft_strncmp(texture[0], "WE", ft_strlen(texture[0])))
		map->we = ft_strtrim(texture[1], "\n");
	else if (!ft_strncmp(texture[0], "EA", ft_strlen(texture[0])))
		map->ea = ft_strtrim(texture[1], "\n");
	else
	{
		map->f_c = ft_strtrim(texture[1], "\n");
		if (!get_colors(map, texture[0]))
			return (0);
	}
	return (1);
}

int	get_textures(char *line, t_map *map)
{
	char	**texture;

	texture = ft_split(line, ' ');
	if (texture[0] && texture[1])
	{
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
		else if (!get_textures2(texture, map))
			return (return_and_free(texture));
	}
	free_2d((void **)texture);
	return (1);
}
