/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:36:04 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/12 00:57:33 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (acessisgood(ac, av))
		return (1);
	mlx.map = readmap(av);
	if (!mlx.map)
		return (1);
	if (ismapvalid(mlx.map) == 0)
	{
		free_map(mlx.map);
		return (1);
	}
	mlx.collectme = countcollects(mlx.map);
	mlx.moves = 0;
	initial_mlx(&mlx);
	loadtexture(&mlx);
	initialplayer(&mlx);
	mapredring(&mlx);
	mlx_hook(mlx.win, 17, 0, clean_exit, &mlx);
	mlx_key_hook(mlx.win, hookwasd, &mlx);
	mlx_loop(mlx.mlx);
	free_map(mlx.map);
	return (0);
}
