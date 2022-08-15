# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosch <lrosch@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 14:07:55 by lrosch            #+#    #+#              #
#    Updated: 2021/10/27 15:13:28 by lrosch           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =		gcc
NAME =		libftplus.a
CFLAGS	=	-Wall -Werror -Wextra

${NAME}:
	${MAKE} -C ./libft
	ar rc ${NAME} libft/*.o
	${MAKE} -C ./gnl
	ar rc ${NAME} gnl/*.o

all: $(NAME)

bonus: all

clean:
	${MAKE} -C ./libft clean
	${MAKE} -C ./gnl clean

fclean: clean
	rm -f ${NAME}
	${MAKE} -C ./libft fclean
	${MAKE} -C ./gnl fclean

re: fclean all
	${MAKE} -C ./libft fclean
	${MAKE} -C ./gnl fclean