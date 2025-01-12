/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_helpers_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:54:18 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/11 20:58:19 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	hasanotherchar(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P' &&
					map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	countit(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	isshaped(char **map)
{
	size_t	len;
	int		i;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	isclosed(char **map)
{
	int	tol;
	int	i;

	if (!map || !map[0])
		return (0);
	tol = 0;
	while (map[tol])
		tol++;
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[tol - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < tol)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
