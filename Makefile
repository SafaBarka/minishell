NAME = minishell

CFLAGS =  -Wall -Wextra -Werror 

$(NAME):
		@gcc  -fsanitize=address main.c \
		helper-functions/ft_initialize.c\
		helper-functions/ft_store_printable.c\
		helper-functions/ft_list_backslash.c\
		helper-functions/ft_list_dollar.c\
		helper-functions/ft_list_dq.c\
		helper-functions/ft_list_semicolon.c\
		helper-functions/ft_list_sq.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		-D BUFFER_SIZE=60 -o $(NAME) 

all : $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all
