/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:23:55 by elounejj          #+#    #+#             */
/*   Updated: 2022/10/29 13:56:42 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_side(char *line)
{
	if (line[0] == 'N' && line[1] == 'O' && line[3] == ' ')
		return (1);
	else if (line[0] == 'S' && line[1] == 'O' && line[3] == ' ')
		return (1);
	else if (line[0] == 'W' && line[1] == 'E' && line[3] == ' ')
		return (1);
	else if (line[0] == 'E' && line[1] == 'A' && line[3] == ' ')
		return (1);
	return (0);
}
