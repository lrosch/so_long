CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC = get_next_line_utils.c get_next_line.c
NAME = gnl.a

all: ${NAME}

${NAME}: ${SRC}
	${CC} ${CC_FLAGS} -c ${SRC}

bonus:
	${CC} ${CC_FLAGS} -c ${BNS}
	ar r ${NAME} *.o

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all
