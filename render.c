/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:57:26 by youchenn          #+#    #+#             */
/*   Updated: 2022/12/28 12:19:28 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_draw_ceiling(t_data *data, double start, double len)
{
	int	color;

	color = create_rgb(data->map_element.colors.c_red, \
		data->map_element.colors.c_green, data->map_element.colors.c_blue);
	while (start <= len)
	{
		my_mlx_pixel_put(&data->img, data->id, start, color);
		start++;
	}
}

void	ft_draw_floor(t_data *data, double start, double len)
{
	int	color;

	color = create_rgb(data->map_element.colors.f_red, \
		data->map_element.colors.f_green, data->map_element.colors.f_blue);
	while (start <= len)
	{
		my_mlx_pixel_put(&data->img, data->id, start, color);
		start++;
	}
}

int	ft_rendering_wall(t_data *data)
{
	double		wall_height;
	double		starting_point;
	double		dis_projplane;
	double		rayangle;

	rayangle = FOFV / W_WIDTH;
	dis_projplane = (W_WIDTH / 2) / tan(FOFV / 2);
	data->id = 0;
	while (data->id < W_WIDTH)
	{
		data->alpha = fmod((data->player.rotationangle - FOFV / 2 + rayangle), \
			2 * M_PI);
		wall_height = TILE / (data->dis_rays[data->id] * \
		cos(data->alpha - data->player.rotationangle)) * dis_projplane;
		starting_point = (W_HEIGHT / 2) - (wall_height / 2);
		if (starting_point < 0)
			starting_point = 0;
		ft_draw_wall(data, starting_point, \
			(wall_height / 2) + (W_HEIGHT / 2), wall_height);
		ft_draw_ceiling(data, 0, W_HEIGHT / 2 - (wall_height / 2));
		ft_draw_floor(data, (wall_height / 2) + (W_HEIGHT / 2), W_HEIGHT);
		rayangle += FOFV / W_WIDTH;
		data->id++;
	}
	return (data->id = 0, 0);
}
