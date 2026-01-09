# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcolin <mcolin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 21:59:30 by mcolin            #+#    #+#              #
#    Updated: 2026/01/09 14:47:53 by mcolin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
NAME = philo
SRCS_DIR = srcs/
SOURCES =	$(SRCS_DIR)main.c					\
			$(SRCS_DIR)philo.c					\
			$(SRCS_DIR)utils/parsing_utils.c	\
			$(SRCS_DIR)utils/utils.c			\

OBJ_DIR = .build/
OBJS = $(SOURCES:$(SRCS_DIR)%.c=$(OBJ_DIR)%.o)

DEPS = $(SOURCES:$(SRCS_DIR)%.c=$(OBJ_DIR)%.d)

CFLAGS = -MP -MMD -Wall -Werror -Wextra -g
INCLUDE = -I includes/

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDE) -o $(NAME)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p .build/
	@mkdir -p .build/utils
	$(CC) $(CFLAGS) $(INCLUDE) $< -c -o $@

gdb: $(NAME)
	gdb -tui $(NAME)

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all bonus fclean clean re gdb

-include $(DEPS)