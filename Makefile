NAME = minishell

CFLAGS = -Wall -Wextra -Werror 

$(NAME):
		@gcc  main.c \
		helper-functions/norm/ft_parse_line.c \
		helper-functions/norm/ft_error.c \
		helper-functions/norm/ft_store.c \
		helper-functions/norm/ft_split.c \
		helper-functions/norm/ft_create_mask.c \
		helper-functions/norm/ft_fill_mask.c \
		helper-functions/norm/ft_mask_quotes.c \
		helper-functions/norm/ft_free_list.c \
		helper-functions/norm/ft_fill_redirections.c \
		helper-functions/norm/ft_check_redirection.c \
		helper-functions/norm/ft_get_redirections.c \
		helper-functions/norm/ft_exec_pipe.c \
		helper-functions/norm/ft_fork.c \
		helper-functions/norm/ft_dollar_exec.c \
		helper-functions/norm/ft_s_exec.c \
		helper-functions/norm/ft_remove_bq.c \
		helper-functions/norm/ft_fill.c \
		helper-functions/norm/ft_check_dollar.c \
		helper-functions/norm/ft_contain.c \
		helper-functions/norm/ft_dollar.c \
		helper-functions/norm/ft_exec.c \
		helper-functions/norm/ft_strncmp.c \
		helper-functions/norm/ft_store_list.c \
		helper-functions/norm/ft_strdup.c \
		helper-functions/norm/ft_strtrim.c \
		helper-functions/norm/ft_strjoin.c \
		helper-functions/norm/ft_substr.c \
		helper-functions/norm/ft_value.c \
		helper-functions/norm/ft_split_path.c \
		helper-functions/norm/ft_path.c \
		helper-functions/norm/ft_call.c \
		helper-functions/norm/ft_execute_builtin.c \
		helper-functions/norm/ft_execute_redirections.c \
		helper-functions/norm/ft_is_builtin.c \
		helper-functions/norm/ft_exec_nopipe.c \
		helper-functions/norm/ft_list_to_tab.c \
		helper-functions/norm/ft_call_executable.c \
		helper-functions/norm/ft_call_exec.c \
		helper-functions/norm/ft_replace_dollar.c \
		helper-functions/norm/ft_echo.c \
		builtin/cd.c \
		builtin/env.c \
		builtin/exit.c \
		builtin/export.c \
		builtin/export_part.c \
		builtin/export1.c \
		builtin/export2.c \
		builtin/export3.c \
		builtin/export4.c \
		builtin/ft_itoa.c \
		builtin/pwd.c \
		builtin/unset.c \
		builtin/help_func.c \
		builtin/help_func1.c \
		builtin/ft_putnbr_fd.c \
		builtin/home.c \
		helper-functions/ft_check_errors.c \
		term/term_hist.c \
		term/term1.c \
		term/term2.c \
		term/signals.c \
		-g -lncurses -o $(NAME) 

all : $(NAME)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all
