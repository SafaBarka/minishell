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
		helper-functions/ft_exec.c\
		helper-functions/ft_path.c\
		helper-functions/ft_call_executable.c\
		helper-functions/ft_exec_pipe.c\
		helper-functions/ft_split_path.c\
		helper-functions/ft_join.c\
		helper-functions/ft_strncmp.c\
		helper-functions/ft_exec_no_pipe.c\
		ssghuri/export.c\
		-D BUFFER_SIZE=60 -o $(NAME) 

all : $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all
