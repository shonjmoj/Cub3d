/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:26:50 by youchenn          #+#    #+#             */
/*   Updated: 2022/12/28 11:58:33 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	its_a_wall(t_data *data, int x, int y)
{
	int	mapx;
	int	mapy;

	mapx = x / TILE;
	mapy = y / TILE;
	return (data->map_int[mapy][mapx]);
}

int	wall_check(t_data *data, double newx, double newy)
{
	int	x;
	int	y;
	int	dist;
	int	ret;

	x = newx;
	y = newy;
	dist = TILE / 8;
	ret = 0;
	if (its_a_wall(data, x - dist, y - dist) == 1)
		ret = 1;
	if (its_a_wall(data, x + dist, y - dist) == 1)
		ret = 1;
	if (its_a_wall(data, x - dist, y + dist) == 1)
		ret = 1;
	if (its_a_wall(data, x + dist, y + dist) == 1)
		ret = 1;
	return (ret);
}

void	ft_raycasting_calc(t_data *data)
{
	double	move_s;
	double	new_x;
	double	new_y;

	new_x = data->map_element.x_pos;
	new_y = data->map_element.y_pos;
	data->player.rotationangle = fmod(data->player.rotationangle, 2 * M_PI);
	if (data->player.rotationangle < 0)
		data->player.rotationangle += 2 * M_PI;
	data->player.rotationangle += data->player.turndirection * \
		data->player.rotationspeed;
	move_s = data->player.waldirection * data->player.movespeed;
	new_x = data->map_element.x_pos + cos(data->player.rotationangle) * move_s;
	new_y = data->map_element.y_pos + sin(data->player.rotationangle) * move_s;
	new_x = new_x + cos(data->player.rotationangle - (90 * M_PI / 180)) * \
		data->player.left_rightdirection * data->player.movespeed;
	new_y = new_y + sin(data->player.rotationangle - (90 * M_PI / 180)) * \
		data->player.left_rightdirection * data->player.movespeed;
	if (wall_check(data, new_x, data->map_element.y_pos) != 1)
		data->map_element.x_pos = new_x;
	if (wall_check(data, data->map_element.x_pos, new_y) != 1)
		data->map_element.y_pos = new_y;
}
