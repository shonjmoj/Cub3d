/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_field_of_view.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:29:01 by youchenn          #+#    #+#             */
/*   Updated: 2022/12/28 12:08:02 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_field_of_view(t_data *data)
{
	double	rotation;
	int		i;

	rotation = data->player.rotationangle;
	data->player.rotationangle -= FOFV / 2;
	i = W_WIDTH + 1;
	while (--i)
	{
		data->player.rotationangle = fmod(data->player.rotationangle, 2 * M_PI);
		if (data->player.rotationangle <= 0)
			data->player.rotationangle += 2 * M_PI;
		data->rays[data->id] = ft_len_of_line(*data);
		data->dis_rays[data->id] = \
			sqrt(pow((data->map_element.y_pos - data->rays[data->id].y), 2) \
				+ pow((data->map_element.x_pos - data->rays[data->id].x), 2));
		data->player.rotationangle += FOFV / W_WIDTH;
		data->id++;
		if (data->id == W_WIDTH)
			data->id = 0;
	}
	data->player.rotationangle = rotation;
}

int	ft_draw(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	data->map_element.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->map_element.img, \
		&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	ft_raycasting_calc(data);
	ft_draw_field_of_view(data);
	ft_rendering_wall(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->map_element.img, 0, 0);
	mlx_destroy_image(data->mlx, data->map_element.img);
	return (0);
}
