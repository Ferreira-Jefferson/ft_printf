NAME = libftprintf.a
OBJ_DIR = objs

SRC_DIR = ./
UTILS_DIR = utils

MANDATORY_SRC = ft_printf.c

BONUS_SRC = ft_printf_bonus.c

UTILS_SRC = ft_print_char.c ft_print_hex_lower.c \
			ft_print_hex_upper.c ft_print_int.c \
			ft_print_percent.c ft_print_pointer.c \
			ft_print_string.c ft_print_unsigned.c

MANDATORY_SRC := $(addprefix $(SRC_DIR)/, $(MANDATORY_SRC))
UTILS_SRC := $(addprefix $(UTILS_DIR)/, $(UTILS_SRC))
BONUS_SRC := $(addprefix $(SRC_DIR)/, $(BONUS_SRC))

MANDATORY_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(MANDATORY_SRC:.c=.o)))
UTILS_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(UTILS_SRC:.c=.o)))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRC:.c=.o)))

OBJS = $(MANDATORY_OBJ) $(UTILS_OBJ) $(BONUS_OBJ)

LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -Ilibft/

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	cp libft/libft.a temp_lib.a
	cd objs && ar x ../temp_lib.a
	ar -rcs $(NAME) $(OBJS) objs/*.o
	rm -f temp_lib.a

bonus: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)/*.o
	@make -C libft clean

fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all

test: $(NAME)
	cc main.c -L. -lftprintf
	./a.out

.PHONY: all clean fclean re bonus test
