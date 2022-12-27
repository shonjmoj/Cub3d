/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parsing_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:28:43 by elounejj          #+#    #+#             */
/*   Updated: 2022/12/27 15:56:57 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		free_2d((void **)map->map);
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
