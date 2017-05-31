NAME		=	ft_ls

SRC_NAME	=	main.c			\
			my_check_args.c		\
			my_dir_handler.c	\
			my_get_rights.c	\
			my_files_handler.c	\
			my_print_files.c	\
			my_sort.c \
			my_utils.c	\
			my_flags.c	\
			my_cmp.c	\
			my_reverse_cmp.c	\
			my_lst_handler.c	\
			my_listing.c	\

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
