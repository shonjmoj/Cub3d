/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:53:48 by elounejj          #+#    #+#             */
/*   Updated: 2022/10/29 13:53:15 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_ext(char *filename)
{
	int		i;
	int		j;
	char	*ext;

	i = 0;
	ext = NULL;
	j = ft_strlen(filename);
	while (filename[j - 1] >= 0)
	{
		if (filename[j - 1] == '.')
		{
			j--;
			break ;
		}
		j--;
	}
	ext = malloc(sizeof(char) * (j + 2));
	while (filename[i + j])
	{
		ext[i] = filename[i + j];
		i++;
	}
	ext[i] = '\0';
	return (ext);
}

int	check_map_ext(char *filname)
{
	char	*ext;
	char	*tmp;

	tmp = ft_substr(filname, ft_strlen(filname) - 4, 4);
	if (ft_strnstr(filname, ".cub", ft_strlen(filname)) == NULL)
		return (0);
	else if (ft_strncmp(tmp, ".cub", ft_strlen(".cub")))
	{
		free(tmp);
		return (0);
	}
	ext = get_ext(filname);
	if (ft_strncmp(".cub", ext, ft_strlen(".cub")) != 0 || *filname == '.')
	{
		free(ext);
		return (0);
	}
	free(ext);
	return (1);
}
