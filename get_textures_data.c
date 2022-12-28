/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:47:49 by youchenn          #+#    #+#             */
/*   Updated: 2022/12/28 12:14:21 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	invalide_texture(void *img, t_data *data)
{
	(void)data;
	if (!img)
	{
		write(2, "texture invalide\n", 18);
		free_all(data);
		exit(1);
	}
}

void	load_textures2(t_data *data, int a)
{
	data->map_element.img_data[2] = \
		(int *)mlx_get_data_addr(data->map_element.img, \
		&a, &a, &a);
	data->map_element.img = \
		mlx_xpm_file_to_image(data->mlx, data->map_element.we, \
		&data->map_element.width[3], &data->map_element.height[3]);
	invalide_texture(data->map_element.img, data);
	data->map_element.img_data[3] = \
		(int *)mlx_get_data_addr(data->map_element.img, \
		&a, &a, &a);
}

void	load_textures(t_data *data)
{
	int	a;

	data->map_element.img_data = (int **)malloc((sizeof(int *) * 4));
	data->map_element.img = mlx_xpm_file_to_image(data->mlx, \
		data->map_element.ea, &data->map_element.width[0], \
		&data->map_element.height[0]);
	invalide_texture(data->map_element.img, data);
	data->map_element.img_data[0] = \
		(int *)mlx_get_data_addr(data->map_element.img, &a, &a, &a);
	data->map_element.img = \
		mlx_xpm_file_to_image(data->mlx, data->map_element.no, \
		&data->map_element.width[1], &data->map_element.height[1]);
	invalide_texture(data->map_element.img, data);
	data->map_element.img_data[1] = \
		(int *)mlx_get_data_addr(data->map_element.img, \
		&a, &a, &a);
	data->map_element.img = \
		mlx_xpm_file_to_image(data->mlx, data->map_element.so, \
		&data->map_element.width[2], &data->map_element.height[2]);
	invalide_texture(data->map_element.img, data);
	load_textures2(data, a);
}
