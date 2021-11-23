NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =  srcs/main.c srcs/ft_check_arg.c \
		srcs/ft_parse_arg.c srcs/ft_move.c\
		srcs/ft_sa.c srcs/ft_sb.c \
		srcs/ft_ss.c srcs/ft_pa.c \
		srcs/ft_pb.c srcs/ft_ra.c \
		srcs/ft_rb.c srcs/ft_rr.c \
		srcs/ft_rra.c srcs/ft_rrb.c \
		srcs/ft_rrr.c srcs/ft_sort.c \
		srcs/ft_small_sort.c srcs/ft_big_sort.c \
		srcs/ft_replace_arg.c srcs/ft_rotate_pile.c

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
	rm -f ${OBJS}

re: fclean clean all
