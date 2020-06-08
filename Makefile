NAME = minishell

LIB_DIR = ./libft
SRC = main.c commands.c
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C $(LIB_DIR)
	@gcc $(FLAGS) $(SRC) $(LIB_DIR)/libft.a -o $(NAME)
	@make clean

clean:
	@make -C $(LIB_DIR) clean

fclean:
	@make -C $(LIB_DIR) fclean
	@rm -f $(NAME)

re: fclean all