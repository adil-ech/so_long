/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemyndutils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 20:08:34 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/12 00:56:26 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	onscreenmoves(t_mlx *mlx)
{
	char	*moves;

	moves = ft_itoa(mlx->moves);
	mlx_string_put(mlx->mlx, mlx->win, 10, 10, 0xFF2D00, "Moves:");
	mlx_string_put(mlx->mlx, mlx->win, 70, 10, 0xFF2D00, moves);
	free(moves);
}
