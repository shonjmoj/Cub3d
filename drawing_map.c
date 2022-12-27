/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:07:48 by youchenn          #+#    #+#             */
/*   Updated: 2022/12/27 18:55:42 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_cub(int i, int j, t_image img, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 10)
	{
		x = -1;
		while (++x < 10)
			my_mlx_pixel_put(&img, \
				(j * 10) + x, (i * 10) + y, color);
	}
}

void	ft_draw_player_x(int i, t_image img, int color)
{
	int	x;
	int	y;

	i = -1;
	while (++i < 21)
	{
		y = -1;
		while (++y < 10)
		{
			x = -1;
			while (++x < 10)
			{
				my_mlx_pixel_put(&img, \
					(0 * 10) + x, ((i - 1) * 10) + y, color);
				my_mlx_pixel_put(&img, \
					(21 * 10) + x, ((i - 1) * 10) + y, color);
				my_mlx_pixel_put(&img, \
					((i + 1) * 10) + x, (0 * 10) + y, color);
				my_mlx_pixel_put(&img, \
					((i + 1) * 10) + x, (20 * 10) + y, color);
				my_mlx_pixel_put(&img, \
					x, (20 * 10) + y, color);
			}
		}
	}
}

void	ft_draw_background(int i, int j, t_image img)
{
	int	x;
	int	y;

	i = -1;
	while (++i < 21)
	{
		j = -1;
		while (++j < 21)
		{
			y = -1;
			while (++y < 10)
			{
				x = -1;
				while (++x < 10)
					my_mlx_pixel_put(&img, \
						(j * 10) + x, (i * 10) + y, 0xD6D58E);
			}
		}
	}
}