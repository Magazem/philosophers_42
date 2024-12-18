SRCS	= philo.c check.c init.c utils.c
OBJS	:= $(SRCS:%.c=%.o)
HEADER = philo.h struct.h
NAME = philo

cc	= cc
RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra

all:	${NAME}

%.o:	%.c
		${CC} ${CFLAGS}	-c $< -o $@

$NAME: philo.c $HEADER

philo: philo.o
		${CC} ${CFLAGS} -o philo

clean:
		${RM} ${OBJ}

fclean: clean
		{RM} philo

re:		fclean all

.PHONY: all clean fclean re