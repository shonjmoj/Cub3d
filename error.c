/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:24:24 by elounejj          #+#    #+#             */
/*   Updated: 2022/11/12 16:37:34 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(const char *error)
{
	printf("Error\n");
	perror(error);
	exit(1);
}

int	return_and_free(void *ptr)
{
	free(ptr);
	return (0);
}

int	free_all_2dtabs(void *ptr1, void *ptr2)
{
	tab2d_length(ptr1);
	tab2d_length(ptr2);
	return (0);
}

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
	}
	free(arr);
	arr = NULL;
}

int	tab2d_length(char **arr)
{
	int	i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i])
			i++;
	}
	return (i);
}
