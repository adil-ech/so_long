/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:03:33 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/11 21:17:39 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmps;

	tmps = (unsigned char *)s;
	while (n > 0)
	{
		*tmps = 0;
		tmps++;
		n--;
	}
}
