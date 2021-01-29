CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_*.c

OBJS = ${SRCS:.c=.o}

RM = rm -f

.c.o:
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${SRCS}:	${OBJS}
	@${CC} -o ${SRCS} ${OBJS}

all:	${SRCS}

clean:
	@${RM} ${OBJS}

fclean:	clean
	@${RM}	${SRCS}

re:		fclean all

.PHONY:	all clean fclean re