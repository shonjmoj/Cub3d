/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:35:07 by youchenn          #+#    #+#             */
/*   Updated: 2022/12/27 17:03:19 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector	ft_len_of_line(t_data data)
{
	t_vector	a_v;
	t_vector	a_h;
	t_vector	step_v;
	t_vector	step_h;
	t_calc		calc;

	ft_horizontal_calc(data, &step_h, &a_h);
	ft_vertical_calc(data, &step_v, &a_v);
	while (1)
	{
		if (!ft_check_vertical(data, &step_v, &a_v, &calc.v))
			break ;
	}
	if (calc.v)
		calc.dis_v = sqrt(pow((data.map_element.y_pos - a_v.y), 2) \
		+ pow((data.map_element.x_pos - a_v.x), 2));
	else
		calc.dis_v = -1;
	while (1)
	{
		if (!ft_check_horizontal(data, &step_h, &a_h, &calc.h))
			break ;
	}
	return (ft_check_calc(data, calc, a_h, a_v));
}
