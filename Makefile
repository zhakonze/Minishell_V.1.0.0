# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qmanamel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/30 13:00:55 by qmanamel          #+#    #+#              #
#    Updated: 2017/07/30 13:00:58 by qmanamel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc


CFLAGS = -Wall -Wextra -Werror


OBJPATH = obj
SRCPATH = src
LIBFT_PATH = libft

INCLUDE_PATH = include/


LIBFT = -L $(LIBFT_PATH)
LIBS = $(LIBFT) -lft

INCLUDES = -I./ -I $(LIBFT_PATH)/includes -I $(INCLUDE_PATH)


OBJ = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)
SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))

SRCSFILES =	main.c\
			env_functions.c\
			input_functions.c\
			cd_builtin.c\
			echo_builtin.c\
			setenv_builtin.c\
			unsetenv_builtin.c\
			execve.c\
			signals.c\
			execve_pipe.c\

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[33mProcessing\033[0m"
	@$(MAKE) -C libft/
	@$(CC) -o $@ $(CFLAGS) $(OBJ) $(LIBS)
	@echo "\033[33mEnd of the Process\033[0m"
	@echo "\033[33mRun using ./minishell\033[0m"

$(OBJ): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	@mkdir -p $(dir $@)
#	@echo "\033[32m"
	@$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<
#	@echo "\033[0m"

clean:
	@/bin/rm -rf $(OBJPATH)
	@$(MAKE) -C libft clean
	@echo "\033[33mCleaned\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@$(MAKE) -C libft fclean
	@echo "\033[33mDone Cleaning\033[0m"

re: fclean all
