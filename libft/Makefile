PROG_NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC

SRCS = ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isws.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_tablen.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strjoin_free.c \
		ft_strrchr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_realloc.c \
		ft_strdup.c \
		ft_putnbr_fd.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_substr.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_free_tab.c \
		ft_lst_get_last.c \
		GNL/get_next_line.c \
		GNL/get_next_line_utils.c \
		ft_Printf/ft_printf.c \
		ft_Printf/ft_putchar.c \
		ft_Printf/ft_putnbr.c \
		ft_Printf/ft_putnbrhex.c \
		ft_Printf/ft_putstr.c

SRC_BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c



OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

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
	@printf "\r${RED}$(bold)[🧹]${NC}$(bold)libft cleaned successfully!\n"
endef
#__________________

$(PROG_NAME): $(OBJS) $(OBJS_BONUS)
	@ar rsc $(PROG_NAME) $(OBJS_BONUS) $(OBJS)
	@echo -n "\033[2K"
	@$(call SUCCESS_MESSAGE, $(PROG_NAME))

so:
	@$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -n "\033[2K"

bonus: $(OBJS_BONUS) $(OBJS)
	ar rsc $(PROG_NAME) $(OBJS_BONUS) $(OBJS)

clean:
	@rm -f $(OBJS) $(PROG_NAME) $(OBJS_BONUS)
	@echo -n "\033[2K"
	@$(call CLEANING_SUCCESS)

fclean: clean
	@rm -f $(PROG_NAME)
	@echo -n "\033[2K"
	@$(call CLEANING_SUCCESS)

re: fclean all

all: $(PROG_NAME)

.PHONY: all clean fclean re bonus
