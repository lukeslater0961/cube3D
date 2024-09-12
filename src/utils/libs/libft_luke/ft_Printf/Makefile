PROG_NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c \
		ft_putstr.c \
		ft_putchar.c \
		ft_putnbrhex.c \
		ft_putnbr.c \



OBJS = $(SRCS:.c=.o)


$(PROG_NAME): $(OBJS)
	ar rsc $(PROG_NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(PROG_NAME)

fclean: clean
	rm -f $(PROG_NAME)

re: fclean all

all: $(PROG_NAME)

.PHONY: all clean fclean re