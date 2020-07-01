# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 22:16:23 by gloras-t          #+#    #+#              #
#    Updated: 2019/10/26 22:22:28 by gloras-t         ###   ########.fr        #
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
	@gcc -c $(FLAGS) $(FILES)
	@ar rc $(NAME) $(OBJ)
	@echo "$(GREEN)complete:$(EOC) $(ITALIC)LIBFT$(EOC)"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
