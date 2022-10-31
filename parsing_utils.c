/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:23:55 by elounejj          #+#    #+#             */
/*   Updated: 2022/10/31 11:30:23 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_side(char *line)
{
	if ((line[0] == 'N' && line[1] == 'O' && line[2] == ' ') ||
		(line[0] == 'S' && line[1] == 'O' && line[2] == ' ') ||
		(line[0] == 'W' && line[1] == 'E' && line[2] == ' ') ||
		(line[0] == 'E' && line[1] == 'A' && line[2] == ' ') ||
		(line[0] == 'F' && line[1] == ' ') || 
		(line[0] == 'C' && line[1] == ' ') ||
		line[0] == '\n')
		return (1);
	return (0);
}

int	valid_texture(char *line)
{
	int i;
	int j;
	int fd;
	char* tmp;
	char* texture;

	i = 3;
	tmp = NULL;
	texture = NULL;
	if (!valid_side(line))
		return(0);
	tmp = ft_strtrim(line, " \n");
	while(tmp[i] == ' ')
		i++;
	j = i;
	while (tmp[i] != 'm')
		i++;
	texture = ft_substr(tmp, j, i);
	free(tmp);
	fd = open(texture, O_RDONLY);
	if (fd == -1)
		return(return_and_free(texture), fd);
	free(texture);
	return(1);
}