/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minixfirst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:27:54 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/09 20:36:48 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapredring(t_mlx *mlx)
{
	int	x;
	int	y;
	int	tsize;

	tsize = TILE_SIZE;
	y = 0;
	while (mlx->map[y])
	{
		x = 0;
		while (mlx->map[y][x])
		{
			if (mlx->map[y][x] == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->texture[0], x * tsize, y * tsize);
			else if (mlx->map[y][x] == '0')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->texture[1], x * tsize, y * tsize);
			else if (mlx->map[y][x] == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->texture[2], x * tsize, y * tsize);
			else if (mlx->map[y][x] == 'E')
			{
				if (mlx->player.x == x && mlx->player.y == y && mlx->collectme > 0)
					mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->texture[6], x * tsize, y * tsize);
				else if (mlx->collectme == 0)
					mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->texture[5], x * tsize, y * tsize);
				else
					mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->texture[3], x * tsize, y * tsize);
			}
			x++;
		}
		y++;
	}
	if (mlx->map[mlx->player.y][mlx->player.x] != 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->texture[4], mlx->player.x * tsize, mlx->player.y * tsize);
}

void	loadtexture(t_mlx *mlx)
{
	int	img_w;
	int	img_h;
	int	i;

	mlx->texture[0] = mlx_xpm_file_to_image(mlx->mlx, "media/walls.xpm", &img_w, &img_h);
	mlx->texture[1] = mlx_xpm_file_to_image(mlx->mlx, "media/floor.xpm", &img_w, &img_h);
	mlx->texture[2] = mlx_xpm_file_to_image(mlx->mlx, "media/keyscollect.xpm", &img_w, &img_h);
    mlx->texture[3] = mlx_xpm_file_to_image(mlx->mlx, "media/closeddoor.xpm", &img_w, &img_h);
    mlx->texture[4] = mlx_xpm_file_to_image(mlx->mlx, "media/player.xpm", &img_w, &img_h);
	mlx->texture[5] = mlx_xpm_file_to_image(mlx->mlx, "media/openeddoor.xpm", &img_w, &img_h);
	mlx->texture[6] = mlx_xpm_file_to_image(mlx->mlx, "media/playerondoor.xpm", &img_w, &img_h);
	i = 0;
	while (i < 7)
	{
		if (!mlx->texture[i])
		{
			write(2, "Error failed texture\n", 21);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	initial_mlx(t_mlx *mlx)
{
	int	w;
	int	h;
	int r;

	w = ft_strlen(mlx->map[0]) * TILE_SIZE;
	r = 0;
	while (mlx->map[r])
		r++;
	h = r * TILE_SIZE;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		write(2, "Error mlx failed\n", 17);
		exit(EXIT_FAILURE);
	}
	mlx->win = mlx_new_window(mlx->mlx, w, h, "so_long_win");
	if (!mlx->win)
	{
		write(2, "Error win failed\n", 17);
		exit(EXIT_FAILURE);
	}
}
