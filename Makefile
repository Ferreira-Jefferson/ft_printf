NAME = libftprintf.a

MANDATORY_SRC = ft_printf.c
UTEIS = $(addprefix utils/, ft_print_char.c ft_print_hex_lower.c \
							ft_print_hex_upper.c ft_print_int.c \
							ft_print_percent.c ft_print_pointer.c \
							ft_print_string.c ft_print_unsigned.c)

MANDATORY_SRC += $(UTEIS)

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

LIBFT = ./libft/libft.a

CC = cc

FLAGS = -Wall -Werror -Wextra -g -I libft/

all: $(NAME)

$(NAME): $(MANDATORY_OBJ)
	make bonus -C ./libft
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