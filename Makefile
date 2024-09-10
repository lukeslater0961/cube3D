PROG_NAME = cube

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I includes

SRCS = main.c \
	   parsing/parsing.c

OBJS = $(SRCS:.c=.o)

#_____Define colors_____
GREEN = \033[0;32m
NC = \033[0m
YELLOW = \033[1;33m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
#______________________

bold := $(shell tput bold)
notbold := $(shell tput sgr0)

#_____MESSAGES_____
define SUCCESS_MESSAGE
	@printf "\r${GREEN}$(bold)[$@ built successfully!]${NC}\n"
endef

define CLEANING_SUCCESS
	@printf "\r${RED}$(bold)[🧹]${NC}$(bold)cube3D cleaned successfully!\n"
endef
#__________________

$(PROG_NAME): $(OBJS)
	@make -s -C libft
	@$(CC) $(CFLAGS) $(OBJS) -o $@ -L ./libft -lft -lreadline
	@echo -n "\033[2K"
	@$(call SUCCESS_MESSAGE, $(PROG_NAME))

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo -n "\033[2K"

clean:
	@make -s clean -C libft
	@rm -f $(OBJS)
	@echo -n "\033[2K"
	@$(call CLEANING_SUCCESS)

fclean: clean
	@rm -f $(PROG_NAME)

re: fclean all

all: $(PROG_NAME)

.PHONY: all clean fclean re
