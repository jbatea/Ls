NAME		=	ft_ls

SRC_NAME	=	main.c			\
			my_check_args.c		\

SRC		=	$(addprefix srcs/, $(SRC_NAME))

OBJ		=	$(SRC:srcs/%.c=.obj/%.o)

CC		=	gcc

FLAGS		= 	-Wall -Werror -Wextra

LIB		= 	-L libft -lft

INCLUDE		= 	-I includes

all: 		$(NAME)

$(NAME): 	lib $(OBJ)
		$(CC) $(OBJ) $(INCLUDE) $(FLAGS) $(LIB) -o $@

.obj/%.o: 	srcs/%.c
		@mkdir -p .obj/
		$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
		@rm -rf .obj/
		@make clean -C libft/

fclean: 	clean
		@rm -rf $(NAME)
		@make fclean -C libft/

re: 		fclean all

lib:
		@make -C libft
