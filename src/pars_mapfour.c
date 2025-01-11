/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_mapfour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:38:02 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/10 22:51:30 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	duplicateme(t_pdata *data, char **rows)
{
	size_t	i;

	i = 0;
	while (rows[i])
		i++;
	data->map_copy = malloc(sizeof(char *) * (i + 1));
	if (!data->map_copy)
		return (0);
	i = 0;
	while (rows[i])
	{
		data->map_copy[i] = ft_strdup(rows[i]);
		if (!data->map_copy[i])
		{
			free_map(data->map_copy);
			return (0);
		}
		i++;
	}
	data->map_copy[i] = NULL;
	return (1);
}

void	locateplayer(char **rows, t_pdata *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (rows[i])
	{
		j = 0;
		while (rows[i][j])
		{
			if (rows[i][j] == 'P')
			{
				data->p_y = i;
				data->p_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	fillmepls(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || x >= (int)ft_strlen(map[y])
		|| map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	fillmepls(map, x + 1, y);
	fillmepls(map, x - 1, y);
	fillmepls(map, x, y + 1);
	fillmepls(map, x, y - 1);
}
