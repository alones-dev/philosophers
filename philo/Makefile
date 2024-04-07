# Base
NAME		=	philo
CC			=	cc
FLAGS		=	-g3 -pthread -Wall -Wextra -Werror

# Base compiled files
INC_FOLDER	=	inc/
SRC_FOLDER	=	srcs/
SRC_FILES	=	main.c arguments.c utils.c init.c time.c philo.c
OBJS		=	$(addprefix $(SRC_FOLDER), $(SRC_FILES:%.c=%.o))

# Colors
DEFAULT		=	\033[0;39m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m

# Compile part
%.o: %.c
	@echo "$(YELLOW)- Compiling $<$(DEFAULT)"
	@$(CC) $(FLAGS) -I$(INC_FOLDER) -c $< -o $@

$(NAME): 	$(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)♫ $(NAME) compiled successfully! ♫$(DEFAULT)"

# Mandatory rules
all:		$(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "$(GREEN)♫ $(NAME) cleaned successfully! ♫$(DEFAULT)"

fclean:		clean
	@rm -f $(NAME)
	@echo "$(GREEN)♫ $(NAME) executable files cleaned! ♫$(DEFAULT)"

re:			fclean all
			@echo "$(GREEN)♫ $(NAME) recompiled successfully! ♫$(DEFAULT)"

.PHONY:		all clean fclean re