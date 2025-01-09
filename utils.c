/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:44:57 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/09 21:31:03 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
}

int	acessisgood(int ac, char **av)
{
	if (ac != 2)
	{
		write (2, "Error give me a file!\n", 22);
		return (1);
	}
	if (access(av[1], F_OK) != 0)
	{
		write(2, "Error map file doesnt exist\n", 28);
		return (1);
	}
	if (access(av[1], R_OK) != 0)
	{
		write(2, "Error map file isnt readable\n", 29);
		return (1);
	}
	return (0);
}
