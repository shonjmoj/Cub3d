/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:09:31 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/13 14:45:19 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int valid_map(char *line, int fd)
{
    if (line[0] == '\n')
        return (return_and_free(line), 0);
    while(1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (line[0] == '\n')
            return (return_and_free(line), 0);
        printf("%s", line);
        free(line);
    }
    return (1);
}

int valid_parsing(t_map *map, int fd)
{
    char *line;

    line = NULL;
    init_map(map);
    while(1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        if (line[0] != '\n' && !completed_config(map))
            if (get_textures(line, map) == 0)
                return (return_and_free(line), 0);
        if (completed_config(map) && line[0] != '\n')
        {
            if (!valid_map(line, fd) && (ft_strchr(line, '1') || \
                ft_strchr(line, '0') || ft_strchr(line, ' '))) 
                return(return_and_free(line), 0);
            break ;
        }
        printf("%s", line);
        free(line);
    }
    return (return_and_free(line), 1);
}