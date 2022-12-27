/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:04:38 by youchenn          #+#    #+#             */
/*   Updated: 2022/12/27 19:11:44 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi_map(char str)
{
	if (str == '0')
		return (0);
	else if (str == '1')
		return (1);
	else if (str == 'N')
		return (N);
	else if (str == 'W')
		return (W);
	else if (str == 'S')
		return (S);
	else if (str == 'W')
		return (W);
	return (-1);
}

int	**ft_to_int(char **map)
{
	int	i;
	int	j;
	int	**n_map;

	i = -1;
	j = -1;
	n_map = ft_malloc(tab2d_length(map) * sizeof(int *));
	while (map[++i])
	{
		j = -1;
		n_map[i] = ft_malloc(ft_strlen(map[i]) * sizeof(int));
		while (map[i][++j])
			n_map[i][j] = ft_atoi_map(map[i][j]);
	}
	return (n_map);
}

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
