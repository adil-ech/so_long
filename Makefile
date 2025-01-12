# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adechaji <adechaji@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 22:52:47 by adechaji          #+#    #+#              #
#    Updated: 2025/01/12 00:57:16 by adechaji         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long
BS_NAME	= so_long_bonus
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
SRCS	= src/ft_printf_extra_utils.c src/ft_printf_utils.c src/ft_printf.c src/ft_strdup.c src/ft_strlen.c \
			src/get_next_line_utils.c src/get_next_line.c src/hooksndutils.c src/minixfirst.c \
			src/pars_map_helpers.c src/pars_map.c src/pars_mapfour.c src/pars_mapthree.c \
			src/playermlx.c src/reading.c src/utils.c so_long.c
BS_SRCS	= src_bonus/ft_printf_bonus.c src_bonus/ft_printf_extra_utils_bonus.c src_bonus/ft_printf_utils_bonus.c \
            src_bonus/ft_strdup_bonus.c src_bonus/ft_strlen_bonus.c src_bonus/get_next_line_bonus.c \
            src_bonus/get_next_line_utils_bonus.c src_bonus/hooksndutils_bonus.c src_bonus/minixfirst_bonus.c \
            src_bonus/pars_map_bonus.c src_bonus/pars_map_helpers_bonus.c src_bonus/pars_mapfour_bonus.c \
            src_bonus/pars_mapthree_bonus.c src_bonus/playermlx_bonus.c src_bonus/reading_bonus.c \
            src_bonus/utils_bonus.c src_bonus/ft_itoa_bonus.c src_bonus/ft_calloc_bonus.c \
			src_bonus/ft_bzero_bonus.c src_bonus/enemyndutils_bonus.c so_long_bonus.c
OBJS	= $(SRCS:.c=.o)
BS_OBJS	= $(BS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus: $(BS_NAME)

$(BS_NAME): $(BS_OBJS)
	$(CC) $(CFLAGS) $(BS_OBJS) -lmlx -framework OpenGL -framework AppKit -o $(BS_NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BS_OBJS)

fclean: clean
	rm -f $(NAME) $(BS_NAME)

re: fclean all