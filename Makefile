NAME = minishell

LIB_DIR = ./libft
SRC = main.c add_list.c print_list.c miniterm.c unsetenv.c arraylen.c setenv.c free_things.c
FLAGS = -Wall -Wextra

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR)
	@gcc $(FLAGS) $(SRC) $(LIB_DIR)/libft.a -g -o $(NAME)
	@make clean

clean:
	@make -C $(LIB_DIR) clean

fclean:
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all