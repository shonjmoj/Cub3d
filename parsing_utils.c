/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:23:55 by elounejj          #+#    #+#             */
/*   Updated: 2022/10/29 15:46:04 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_side(char *line)
{
	if ((line[0] == 'N' && line[1] == 'O' && line[2] == ' ') ||
		(line[0] == 'S' && line[1] == 'O' && line[2] == ' ') ||
		(line[0] == 'W' && line[1] == 'E' && line[2] == ' ') ||
		(line[0] == 'E' && line[1] == 'A' && line[2] == ' '))
		return (1);
	return (0);
}

int	valid_texture(char *line)
{
	int i;
	int j;
	int fd;
	char *texture;

	texture = NULL;
	i = 3;
	if (!valid_side(line))
		return(0);
	while(line[i] == ' ')
		i++;
	j = i;
	while (line[i] == ' ' && line[i])
		i++;
	i++;
	texture = ft_substr(line, j, i);
	fd = open(texture, O_RDONLY);
	if (fd == -1)
	{
		free(texture);
		return (fd);
	}
	free(texture);
	return (1);
}