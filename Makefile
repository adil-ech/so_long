# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 22:52:47 by adechaji          #+#    #+#              #
#    Updated: 2025/01/10 23:06:06 by adechaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
SRCS	= src/ft_printf_extra_utils.c src/ft_printf_utils.c src/ft_printf.c src/ft_strdup.c src/ft_strlen.c \
			src/get_next_line_utils.c src/get_next_line.c src/hooksndutils.c src/minixfirst.c \
			src/pars_map_helpers.c src/pars_map.c src/pars_mapfour.c src/pars_mapthree.c \
			src/playermlx.c src/reading.c src/utils.c so_long.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all