### PROGRAM NAME ###
NAME		:= philo

### UTILS ###
CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror
DEP_FLAGS	:= -MMD -MP
MAKE_FLAG 	:= --no-print-directory --silent
RM 			:= rm -rf

### COLORS ###
DEFAULT    	:= \033[0m
BLACK    	:= \033[0;30m
RED        	:= \033[0;31m
GREEN    	:= \033[0;32m
UGREEN    	:= \033[4;32m
YELLOW    	:= \033[;33m
BLUE    	:= \033[0;34m
PURPLE    	:= \033[0;35m
CYAN    	:= \033[0;36m
BWHITE    	:= \033[1;37m
NEW			:= \r\033[K

### DIRECTORIES ###
SRC_DIR 	:= srcs
INCLD_DIR 	:= inc
OBJS_DIR 	:= objs

### FILES ###
define INCLUDES	:=
	$(INCLD_DIR)/
endef
INCLUDES 	:= $(strip $(INCLUDES))

INCLD_FLAG 	:= $(addprefix -I , $(INCLUDES))

define SRC 	:=
	arguments.c
	init.c
	main.c
	philo.c
	time.c
	utils.c
endef
SRC 		:= $(strip $(SRC))

OBJS 		:= $(patsubst %.c,$(OBJS_DIR)/%.o,$(SRC))
DEPS		:= $(patsubst %.c,$(OBJS_DIR)/%.d,$(SRC))

### PROJECT ###
.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(NEW)$(PURPLE)[$(JP)] $(UGREEN)Building:$(DEFAULT)$(BWHITE) $@$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJS) $(INCLD_FLAG) -o $@
	@printf "\n"

-include $(DEPS)
$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "$(NEW)$(PURPLE)[$(JP)] $(UGREEN)Building:$(DEFAULT) $<"
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(DEP_FLAGS) $(CFLAGS) $(INCLD_FLAG) -c $< -o $@

.PHONY: clean
clean: ; @printf "$(PURPLE)[$(JP)] $(RED)Removing $(DEFAULT)$(OBJS_DIR) files\n"
	@$(RM) $(OBJS_DIR)

.PHONY: fclean
fclean: clean ; @printf "$(PURPLE)[$(JP)] $(RED)Removing $(DEFAULT)$(NAME)\n"
	@$(RM) $(NAME) 

.PHONY: re
re: fclean all
