/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:38:01 by asabbar           #+#    #+#             */
/*   Updated: 2022/12/28 02:59:37 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector ft_position_player(t_data data)
{
	int i;
	int j;
	t_vector posi;

	i = -1;
	while (data.map_element.map[++i])
	{
		j = -1;
		while (data.map_element.map[i][++j])
		{
			if (data.map_element.map[i][j] == 'N' || data.map_element.map[i][j] == 'S' || data.map_element.map[i][j] == 'E' || data.map_element.map[i][j] == 'W')
			{
				posi.y = i;
				posi.x = j;
				return (posi);
			}
		}
	}
	exit(0);
}

void get_player_view()
{
	if (g_player == 'S')
		g_player = 1;	
	if (g_player == 'W')
		g_player = 2;	
	if (g_player == 'E')
		g_player = 4;	
	if (g_player == 'N')
		g_player = 3;	
}

void ft_window(t_data data)
{
	t_vector posi_player;

	data.mlx = mlx_init();

	data.mlx_win = mlx_new_window(data.mlx, W_WIDTH, W_HEIGHT, "CUB3D");
	load_textures(&data);
	data.player.turndirection = 0;
	data.player.waldirection = 0;
	data.player.rotationangle = g_player * M_PI / 2;
	data.player.movespeed = 2;
	data.player.rotationspeed = 3 * (M_PI / 180);
	posi_player = ft_position_player(data);
	data.map_element.y_pos = (posi_player.y) * TILE + TILE / 2;
	data.map_element.x_pos = (posi_player.x) * TILE + TILE / 2;
	data.posi_player = posi_player;
	data.is_clicked = false;
	data.mouse.x = 0;
	mlx_hook(data.mlx_win, 2, 0L, key_hook, &data);
	mlx_hook(data.mlx_win, 17, 0L, cross_x, &data);
	mlx_hook(data.mlx_win, 3, 0L, key_release, &data);
	mlx_loop_hook(data.mlx, ft_draw, &data);
	mlx_loop(data.mlx);
}

void free_all(t_data *data)
{
	(void)data;

	if (data->map_element.ea)
		free(data->map_element.ea);
	if (data->map_element.we)
		free(data->map_element.we);
	if (data->map_element.so)
		free(data->map_element.so);
	if (data->map_element.no)
		free(data->map_element.no);
	free(data->value);
	exit(1);
}

// void f()
// {
// 	system("leaks cub3D");
// }

// int	main(int ac, char **av)
// {
// 	t_data		data;
// 	char		**map;

// 	atexit(f);
// 	if (ac == 1 || ac > 2)
// 		return (printf("Error \n number of argm is invalide\n"), 1);
// if (!valid_parsing(data.map_element.map))
// 	exit(1);
// if (!data.value)
// 	return (1);
// if (ft_check_value(&data, data.value, &data.textures, &data.color))
// 	free_all(&data);
// if (ft_check_new_line(data.value))
// 	free_all(&data);
// map = ft_map(data.value);
// data.map = ft_new_map(map);
// ft_fre(map);
// if (!ft_check_map(data.map, 0, 0))
// 	return (free_all(&data), 1);
// ft_map_wall(&data, 0, 0);
// data.id = 0;
// ft_front_of_player(&data);
// ft_virtualwall(&data);
int main(int argc, char **argv)
{
	t_data data;
	int fd;

	g_player = -1;
	init_map(&data.map_element);
	if (argc != 2)
		print_error("Invalid arguments !");
	if (!check_map_ext(argv[1]))
		print_error("Invalid map file !");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Cannot open this file !");
	if (!valid_parsing(&data.map_element, fd))
		print_error("Invalid map config !");
	get_player_view();
	data.map_y = tab2d_length(data.map_element.map);
	data.map_x = long_line(data.map_element.map);
	data.map_int = ft_to_int(data.map_element.map, data.map_y, data.map_x);
	// int i = 0;
	// while (i < data.map_y)
	// {
	// 	int j = 0;
	// 	while (j < data.map_x)
	// 	{
	// 		printf("%d ", data.map_int[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	data.id = 0;
	ft_window(data);
	return (0);
}
