NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =  srcs/main.c srcs/ft_check_arg.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${MAKE} -C ./libft
	${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

fclean: clean
	${MAKE} fclean -C ./libft
	rm -f ${NAME}

clean:
	${MAKE} clean -C ./libft
	rm -f ${NAME} ${OBJS}

re: fclean clean all
