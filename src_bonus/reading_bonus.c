/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:34:20 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/11 17:29:54 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static char	*cutnewline(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

static int	retlen(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (i);
}

static char	**readlines(int len, int fd)
{
	char	**map;
	char	*line;
	int		i;

	map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = cutnewline(line);
		if (!map[i])
		{
			free_map(map);
			return (NULL);
		}
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

char	**readmap(char **av)
{
	int		fd;
	int		len;
	char	**map;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	len = retlen(fd);
	close(fd);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = readlines(len, fd);
	close(fd);
	if (!map)
		return (NULL);
	return (map);
}
