# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 22:16:23 by gloras-t          #+#    #+#              #
#    Updated: 2020/07/03 21:46:17 by slindgre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
FILES = *.c
OBJ = *.o

ITALIC = \033[3m
GREEN = \033[0;32m
YELLOW = \033[1;33m
EOC = \033[0m

all: $(NAME)

$(NAME): $(FILES)
	@gcc -c $(FLAGS) $(FILES) -g
	@ar rc $(NAME) $(OBJ)
	@echo "$(GREEN)complete:$(EOC) $(ITALIC)LIBFT$(EOC)"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
