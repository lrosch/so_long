# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/14 12:17:05 by lrosch            #+#    #+#              #
#    Updated: 2021/10/27 15:16:04 by lrosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	gcc
NAME =	so_long.a
FLAGS =	-Wall -Wextra -Werror
MLX	=	-Lminilibx -lmlx -framework OpenGL -framework AppKit
SRC	=	button_events.c enclosure_check.c map_checking.c \
		map_functions.c movement_utils.c so_long_utils.c \
		so_long.c

all: $(NAME)

$(NAME): *.c
	$(MAKE) -C ./libftp
	$(MAKE) -C ./minilibx
	cp libftp/libftplus.a $(NAME)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	$(CC) $(FLAGS) -L. so_long.a ./minilibx/libmlx.a $(MLX) *.o -o so_long

clean:
	rm -f *.o
	${MAKE} -C ./libftp clean
	${MAKE} -C ./minilibx clean

fclean: clean
	rm -f $(NAME)
	rm -f so_long
	${MAKE} -C ./libftp fclean

re: fclean
	${MAKE} -C ./libftp fclean
	${MAKE} -C ./minilibx clean
	${MAKE} all