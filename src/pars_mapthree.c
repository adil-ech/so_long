/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_mapthree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:20:26 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/10 22:51:33 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	reachtrue(t_pdata *data, char **rows)
{
	int	i;
	int	j;

	i = 0;
	while (rows[i])
	{
		j = 0;
		while (rows[i][j])
		{
			if (rows[i][j] == 'C' && data->map_copy[i][j] != 'V')
				data->collects++;
			if (rows[i][j] == 'E' && data->map_copy[i][j] != 'V')
				data->fexit++;
			j++;
		}
		i++;
	}
}

void	isitreachable(char **rows)
{
	t_pdata	data;

	data.collects = 0;
	data.fexit = 0;
	data.p_x = -1;
	data.p_y = -1;
	if (!duplicateme(&data, rows))
	{
		free_map(rows);
		exit(1);
	}
	locateplayer(rows, &data);
	fillmepls(data.map_copy, data.p_x, data.p_y);
	reachtrue(&data, rows);
	free_map(data.map_copy);
	if (data.collects > 0 || data.fexit > 0)
	{
		write(1, "Error map is unwinable\n", 23);
		free_map(rows);
		exit(1);
	}
}
