.SILENT: ${NAME}

SRCS = main.c utils.c init.c routine.c checks.c
OBJS := $(SRCS:%.c=%.o)
HEADER = philo.h struct.h
NAME = philo

cc = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -pthread -g

#Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
LIGHT_YELLOW = \033[1;33m
BOLD		= \033[1m
NORMAL		= \033[0m
UP			= \033[A
CUT			= \033[K
CYAN 		= \033[0;36m

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} -g ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "$(CYAN)OBJS compiling..."
	@echo "$(RED)$(BOLD)⤙ philo: $(GREEN)complied and ready $(LIGHT_YELLOW)[$(GREEN)✔$(LIGHT_YELLOW)]$(RED)$(BOLD) ⤚"

clean:
	@${RM}	${OBJS}
	@echo "$(RED)$(CUT)cleaning OBJS 🗑"

fclean:	clean
		@${RM} ${NAME}
		@echo "$(RED)$(UP)cleaning everything 💣"

re: fclean all

.PHONY: all clean fclean re