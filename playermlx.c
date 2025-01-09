/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:33:46 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/09 19:30:44 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveplayer(t_mlx *mlx, int old_x, int old_y)
{
	char	prv;	
	int		new_x;
	int		new_y;

	new_x = mlx->player.x + old_x;
	new_y = mlx->player.y + old_y;
	prv = mlx->map[new_y][new_x];
	if (prv != '1')
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
		if (mlx->map[mlx->player.y][mlx->player.x] != 'E')
			mlx->map[mlx->player.y][mlx->player.x] = '0';
		mlx->player.x = new_x;
		mlx->player.y = new_y;
		if (prv != 'E')
			mlx->map[new_y][new_x] = 'P';
		mlx->moves++;
		ft_printf("moves : %d\n", mlx->moves);
		mapredring(mlx);
	}
}

void	initialplayer(t_mlx *mlx)
{
	int	y;
	int x;

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
