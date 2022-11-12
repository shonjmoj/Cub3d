/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:53:48 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/12 15:42:59 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int	all_digit(char *line)
{
	int	i;

	i = 0;
	while(line[i])
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

int	get_colors(t_map *map)
{
	char **c;
	char **f;


	c = NULL;
	f = NULL;
	c = ft_split(map->ceilling, ',');
	f = ft_split(map->floor, ',');
	if (tab2d_length(c) != 3 || tab2d_length(f) != 3 || \
		!all_digit(c[0]) || !all_digit(c[1]) ||\
		!all_digit(c[2]) || !all_digit(f[0]) || \
		!all_digit(f[1]) || !all_digit(f[2]))
		return(free_all_2dtabs(c, f), 0);
	map->colors.c_red = ft_atoi(c[0]);
	map->colors.c_green = ft_atoi(c[1]);
	map->colors.c_blue = ft_atoi(c[2]);
	map->colors.f_red = ft_atoi(f[0]);
	map->colors.f_green = ft_atoi(f[1]);
	map->colors.f_blue = ft_atoi(f[2]);
	free_all_2dtabs(c, f);
	return (1);
}
