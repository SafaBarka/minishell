NAME = minishell

CFLAGS =  -Wall -Wextra -Werror 

$(NAME):
		@gcc  -fsanitize=address main.c \
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		helper-functions/ft_write.c\
		helper-functions/ft_dollar.c\
		helper-functions/ft_create_mask.c\
		helper-functions/ft_check_errors.c\
		helper-functions/ft_split.c\
		helper-functions/ft_sub.c\
		helper-functions/ft_store_list.c\
		helper-functions/ft_strtrim.c\
		helper-functions/ft_store.c\
		-D BUFFER_SIZE=60 -o $(NAME) 

all : $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all
