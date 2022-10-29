/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elounejj <elounejj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:11:22 by elounejj          #+#    #+#             */
/*   Updated: 2022/10/29 12:15:09 by elounejj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_join_and_free(char **str, void *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buf);
	ft_free(str);
	*str = tmp;
	return ;
}

char	*ft_free(char **adr_str)
{
	if (adr_str != NULL && *adr_str != NULL)
	{
		free(*adr_str);
		*adr_str = NULL;
	}
	return (NULL);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_line(ssize_t readr, char **str_input)
{
	int		len;
	char	*tmp;
	char	*str_return;

	if (readr == 0 && **str_input == '\0')
	{
		ft_free(str_input);
		return (NULL);
	}
	len = 0;
	while ((*str_input)[len] != '\n' && (*str_input)[len] != '\0')
		len++;
	if ((*str_input)[len] == '\n')
	{
		str_return = ft_substr(*str_input, 0, len + 1);
		tmp = ft_strdup(&(*str_input)[len + 1]);
		ft_free(str_input);
		*str_input = tmp;
		return (str_return);
	}
	str_return = ft_substr(*str_input, 0, len);
	ft_free(str_input);
	return (str_return);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		readr;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	readr = 1;
	while (readr)
	{
		readr = read(fd, buf, BUFFER_SIZE);
		if (readr == -1)
			return (NULL);
		buf[readr] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else if (str != NULL)
			ft_join_and_free(&str, buf);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (get_line(readr, &str));
}
