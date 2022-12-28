/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mouvement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:30:07 by elounejj          #+#    #+#             */
/*   Updated: 2022/12/28 11:48:26 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_movement(int x, int y, t_data *data)
{
	if ((x >= 0 && x < W_WIDTH) && (y >= 0 && y < W_HEIGHT))
	{
		if (x > data->mouse.x)
		{
			data->player.rotationangle -= (data->player.rotationspeed * \
				(x - data->mouse.x) * M_PI / 180);
		}
		else if (x < data->mouse.x)
			data->player.rotationangle += (data->player.rotationspeed * \
				(data->mouse.x - x) * M_PI / 180);
		data->mouse.x = x;
		data->mouse.y = y;
	}
	return (0);
}
