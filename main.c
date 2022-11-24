/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:54:01 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/24 15:32:33 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		fd;

	g_player = -1;
	init_map(&map);
	if (argc != 2)
		print_error("Invalid arguments !");
	if (!check_map_ext(argv[1]))
		print_error("Invalid map file !");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Cannot open this file !");
	if (!valid_parsing(&map, fd))
		print_error("Invalid map config !");
	return (0);
}
