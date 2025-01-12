/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermlx_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:33:46 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/11 21:32:23 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	normsplit(t_mlx *mlx, int new_x, int new_y, char prv)
{
	if (prv == 'C')
	{
		mlx->map[new_y][new_x] = '0';
		mlx->collectme--;
	}
	if (prv == 'E' && mlx->collectme == 0)
	{
		write(1, "🎉!🎉!🎉!🎉!🎉!🎉! YOU WON !🎉!🎉!🎉!🎉!🎉!🎉!\n", 71);
		exit(EXIT_SUCCESS);
	}
	if (prv == 'X')
	{
		write(1, "{{{LOSEEER U CANT WIN AN EASY GAME?}}}\n", 39);
		exit(EXIT_SUCCESS);
	}
	if (mlx->map[mlx->player.y][mlx->player.x] != 'E')
		mlx->map[mlx->player.y][mlx->player.x] = '0';
	mlx->player.x = new_x;
	mlx->player.y = new_y;
	if (prv != 'E')
		mlx->map[new_y][new_x] = 'P';
	mlx->moves++;
	mapredring(mlx);
	onscreenmoves(mlx);
}

void	moveplayer(t_mlx *mlx, int old_x, int old_y)
{
	char	prv;	
	int		new_x;
	int		new_y;

	new_x = mlx->player.x + old_x;
	new_y = mlx->player.y + old_y;
	prv = mlx->map[new_y][new_x];
	if (prv != '1')
		normsplit(mlx, new_x, new_y, prv);
}

void	initialplayer(t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == 'P')
			{
				mlx->player.x = x;
				mlx->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
