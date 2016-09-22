NAME = ft_ls

INC = ./inc/

INC_LIBFT = ./libft/

CC = gcc -g -Wall -Wextra -Werror

SRC = ./src/add_node.c \
		./src/color.c \
		./src/copy_dir.c \
		./src/copy_opt.c \
		./src/display.c \
		./src/error.c \
		./src/file.c \
		./src/format_dir.c \
		./src/free_tree.c \
		./src/init.c \
		./src/init_perm.c \
		./src/init_time.c \
		./src/init_time_s.c \
		./src/len_dir.c \
		./src/ls.c \
		./src/main.c \
		./src/node_not_l.c \
		./src/node_opt_l.c \
		./src/not_recursive.c \
		./src/print_tree.c \
		./src/print_tree_l.c \
		./src/recursive.c \
		./src/recursive_bis.c \
		./src/search_arg.c \
		./src/sort_dir.c \
		./src/sort_dir_error.c \
		./src/sort_dir_file.c \
		./src/sort_path.c \
		./src/sort_time.c \
		./src/space.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(SRC) -I$(INC) -I$(INC_LIBFT) libft/libft.a -o $(NAME)

$(OBJ)%.o: $(SRC)%.c
	@$(CC) -I$(INC) -o $@ -c $<

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
