NAME = minishell

CFLAGS =  -Wall -Wextra -Werror 

$(NAME):
		@gcc  -fsanitize=address main.c \
		helper-functions/ft_strdup.c\
		helper-functions/ft_create_mask.c\
		helper-functions/ft_split_semicolon.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		-D BUFFER_SIZE=60 -o $(NAME) 

all : $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all
