/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:31:31 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/16 14:10:00 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	parsmap(char **map)
{
	if (!map || !map[0])
	{
		write(2, "Error map is empty || NULL\n", 27);
		return (0);
	}
	if (isshaped(map) == 0)
	{
		write(2, "Error in map shape\n", 19);
		return (0);
	}
	if (isclosed(map) == 0)
	{
		write(2, "Error map isnt surr by walls!\n", 30);
		return (0);
	}
	if (hasanotherchar(map) == 0)
	{
		write(2, "Error map has an invalid char\n", 30);
		return (0);
	}
	return (1);
}

static int	mapelements(char **map)
{
	int	collectme;
	int	exits;
	int	spawns;

	exits = countit(map, 'E');
	spawns = countit(map, 'P');
	collectme = countit(map, 'C');
	if (exits != 1)
	{
		write(2, "Error gimme 1 exit!\n", 20);
		return (0);
	}
	if (spawns != 1)
	{
		write(2, "Error gimme 1 spawn point!\n", 27);
		return (0);
	}
	if (collectme < 1)
	{
		write(2, "Error gimme 1 or more items to collect!\n", 40);
		return (0);
	}
	return (1);
}

static int	checkhw(char **map)
{
	int	h;
	int	w;

	h = 0;
	w = ft_strlen(map[0]);
	while (map[h])
		h++;
	if (h > 19 || w > 34)
	{
		write(2, "Error Map is too big\n", 22);
		return (0);
	}
	return (1);
}

int	ismapvalid(char **map)
{
	if (!map || !map[0])
		return (0);
	if (parsmap(map) == 0)
		return (0);
	if (mapelements(map) == 0)
		return (0);
	if (checkhw(map) == 0)
		return (0);
	isitreachable(map);
	return (1);
}
