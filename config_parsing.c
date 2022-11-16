/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:53:48 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/16 11:00:11 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	all_digit(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*get_ext(char *filename)
{
	int		i;
	int		j;
	char	*ext;

	i = 0;
	ext = NULL;
	j = ft_strlen(filename);
	while (filename[j - 1] >= 0)
	{
		if (filename[j - 1] == '.')
		{
			j--;
			break ;
		}
		j--;
	}
	ext = malloc(sizeof(char) * (j + 2));
	while (filename[i + j])
	{
		ext[i] = filename[i + j];
		i++;
	}
	ext[i] = '\0';
	return (ext);
}

int	check_map_ext(char *filname)
{
	char	*ext;
	int		len;

	len = ft_strlen(filname);
	if (ft_strnstr(filname, ".cub", ft_strlen(filname)) == NULL || \
		filname[len - 1] != 'b' || \
		filname[len - 2] != 'u' || filname[len - 3] != 'c')
		return (0);
	ext = get_ext(filname);
	if (ft_strncmp(".cub", ext, ft_strlen(".cub")) != 0 || *filname == '.')
	{
		free(ext);
		return (0);
	}
	free(ext);
	return (1);
}

void	set_colors(char **colors, t_map *map, char type)
{
	if (type == 'C')
	{
		map->colors.c_red = ft_atoi(colors[0]);
		map->colors.c_green = ft_atoi(colors[1]);
		map->colors.c_blue = ft_atoi(colors[2]);
	}
	else if (type == 'F')
	{
		map->colors.f_red = ft_atoi(colors[0]);
		map->colors.f_green = ft_atoi(colors[1]);
		map->colors.f_blue = ft_atoi(colors[2]);
	}
}

int	get_colors(t_map *map, char *type)
{
	char	**colors;

	colors = NULL;
	colors = ft_split(map->f_c, ',');
	if (tab2d_length(colors) != 3)
	{
		free_2d(colors);
		return (0);
	}
	if (!all_digit(colors[0]) || !all_digit(colors[1]) || \
		!all_digit(colors[2]) || ft_atoi(colors[0]) < 0 || \
		ft_atoi(colors[0]) > 255 || ft_atoi(colors[1]) < 0 || \
		ft_atoi(colors[1]) > 255 || ft_atoi(colors[2]) < 0 || \
		ft_atoi(colors[2]) > 255)
	{
		free_2d(colors);
		return (0);
	}
	set_colors(colors, map, type[0]);
	free_2d(colors);
	free(map->f_c);
	return (1);
}
