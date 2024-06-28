# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dparada <dparada@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 11:04:19 by dparada           #+#    #+#              #
#    Updated: 2024/06/28 10:43:24 by dparada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= clang
NAME 	= minishell
USER 	= dparada
CFLAGS 	= -Wall -Wextra -Werror -g
LIBFT = lib/LIBFT
SRC_DIR = src/
OBJ_DIR = obj/
MINISHELL_H = $(NAME).h
LIB = -lreadline

MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY 	= \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD	= \033[1m
RED		= \033[31;1m

SRC_FILES = executer/built_ins/cd \
			executer/built_ins/echo \
			executer/built_ins/env \
			executer/built_ins/exit \
			executer/built_ins/export \
			executer/built_ins/pwd \
			executer/built_ins/unset \
			executer/utils/env_utils \
			executer/utils/exec_utils \
			executer/utils/general_utils \
			executer/utils/tokens_utils \
			executer/executor \
			parser/cmds_create \
			parser/cmds_utils \
			parser/create_cmd_matrix \
			parser/create_token \
			parser/env \
			parser/expand_types \
			parser/expand \
			parser/free \
			parser/init \
			parser/prints \
			parser/redirecc \
			parser/states \
			parser/token_utils \
			parser/tokens \
			parser/utils \
			parser/main
			

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o,$(SRC_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME): compiling $(OBJ)
		@echo
		@make all -C $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJ) $(LIB) -L$(LIBFT) -lft -o $(NAME)
		@echo "$(MAGENTA)Minishell compiled!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(MINISHELL_H)| $(OBJF)
		@mkdir -p $(dir $@)º
		@echo "$(BLUE)Compiling: $(RESET)$(notdir $<)"
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c | $(OBJF)
		@echo "$(WHITE)Compiling: $(RESET)$(notdir $<)"
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)

compiling:
		@echo "$(RED)Compiling Minishell: $(RESET)"

clean:
		@rm -rf $(OBJ_DIR)
		@make clean -C $(LIBFT)
		@echo "$(RED)Cleaning Minishell's objects. $(RESET)"
		@echo

fclean:
		@rm -rf $(OBJ_DIR)
		@rm -rf $(NAME)
		@make fclean -C $(LIBFT)
		@echo "$(RED)Cleaning Minishell's executables.$(RESET)"

re: fclean all

.PHONY: all clean fclean re compiling 
