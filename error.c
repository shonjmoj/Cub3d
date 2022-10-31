/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:24:24 by elounejj          #+#    #+#             */
/*   Updated: 2022/10/31 10:54:08 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(const char *error)
{
	printf("Error\n");
	perror(error);
	exit(1);
}


int return_and_free(void *ptr)
{
	free(ptr);
	return (0);
}