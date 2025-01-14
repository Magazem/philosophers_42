#COLORS
GREEN		= \033[0;32m
RED 		= \033[0;31m
BOLD		= \033[1m
NORMAL		= \033[0m
UP 			= \033[A
CUT 		= \033[K

SRCS	= philo.c check.c init.c utils.c routine.c
OBJS	:= $(SRCS:%.c=%.o)
HEADER = philo.h struct.h
NAME = philo

cc	= cc
RM	= rm -f
AR	= ar rcs
MKDIR = mkdir -p
LIBS = -lft -L$(LIBFT_DIR)
CFLAGS	= -Wall -Werror -Wextra  -pthread

all: ${NAME}

#Compile normal executable
${NAME}: ${OBJS}
	@${CC} -g ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) created and compiled object files"
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) $(BOLD)$(NAME)$(NORMAL) is ready"

#Clean obj files
clean:
	@${RM} ${OBJS}
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) object files deleted"

#Clean objs files and name
fclean:	clean
	@${RM} ${NAME}
	@echo "$(GREEN)[$(BOLD)OK$(NORMAL)$(GREEN)]$(NORMAL) $(BOLD)$(NAME)$(NORMAL) deleted"

re: fclean all

.PHONY: all clean fclean re