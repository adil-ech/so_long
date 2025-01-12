/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:16:21 by adechaji          #+#    #+#             */
/*   Updated: 2025/01/11 17:39:22 by adechaji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../so_long_bonus.h"

int	ft_printf(const char *str, ...);
int	ft_putchar(int c);
int	ft_putstr(const char *str);
int	ft_putnbr(int n);
int	print_hex(unsigned long num);
int	ft_put_uns_nbr(unsigned int n);
int	print_low_hex(unsigned int num);
int	print_up_hex(unsigned int num);

#endif