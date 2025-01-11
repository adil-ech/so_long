/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooksndutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:43:10 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/10 22:51:16 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	hookwasd(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		clean_exit(mlx);
		exit(EXIT_SUCCESS);
	}
	if (key == 13)
		moveplayer(mlx, 0, -1);
	if (key == 1)
		moveplayer(mlx, 0, 1);
	if (key == 0)
		moveplayer(mlx, -1, 0);
	if (key == 2)
		moveplayer(mlx, 1, 0);
	return (0);
}

int	countcollects(char **map)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
