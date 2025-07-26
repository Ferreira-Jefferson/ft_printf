NAME = libftprintf.a

MANDATORY_SRC = ft_putchar.c

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

LIBFT = ./libft/libft.a

CC = cc

FLAGS = -Wall -Werror -Wextra -g -I libft/

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	make -C ./libft
	ar -rcsT $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
	ar -rcsT $(NAME) $@

bonus:
	@$(MAKE) MANDATORY_SRC="$(MANDATORY_SRC) $(BONUS_SRC)"

clean:
	rm -f $(MANDATORY_OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	cc main.c -L. -lftprintf
	./a.out

.PHONY: all clean fclean re bonus