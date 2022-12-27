/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:04:38 by youchenn          #+#    #+#             */
/*   Updated: 2022/12/27 16:45:37 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	**ft_to_int(char **map)
// {
// 	int	i;
// 	int	j;
// 	int	**n_map;

// 	i = -1;
// 	j = -1;
// 	n_map = ft_malloc(ft_lenmap(map) * sizeof(int *));
// 	while (map[++i])
// 	{
// 		j = -1;
// 		n_map[i] = ft_malloc(ft_strlen(map[i]) * sizeof(int));
// 		while (map[i][++j])
// 			n_map[i][j] = ft_atoi_map(map[i][j]);
// 	}
// 	return (n_map);
// }

int	long_line(char **str)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	j = 0;
	max = ft_strlen(str[i]);
	while (str[i])
	{
		if ((int)ft_strlen(str[i]) > max)
			max = ft_strlen(str[i]);
		i++;
	}
	return (max);
}

void	*ft_malloc(int size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		printf("Error\nmalloc error\n");
		exit(1);
	}
	return (ptr);
}
