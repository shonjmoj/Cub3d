/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parsing_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:28:43 by elounejj          #+#    #+#             */
/*   Updated: 2022/12/28 12:07:21 by elounejj         ###   ########.fr       */
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

int	completed_config(t_map *map)
{
	if (!map->no || !map->so || !map->we || !map->ea || \
		map->colors.c_red == -1 || map->colors.c_green == -1 || \
		map->colors.c_blue == -1 || map->colors.f_red == -1 || \
		map->colors.f_green == -1 || map->colors.f_blue == -1)
		return (0);
	return (1);
}
