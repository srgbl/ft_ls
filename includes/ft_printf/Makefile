# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/01 12:49:11 by gloras-t          #+#    #+#              #
#    Updated: 2019/10/29 19:51:01 by slindgre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftp.a

TEST = t

FLAGS = -Wall -Wextra -Werror

FLOAT = float/

UTILS = utils/

HANDLERS = handlers/

TRANSFORMS = transforms/

SRC =	ft_printf.c \
		ft_prepare_to_print.c \
		type_table.c \
		$(FLOAT)ft_float.c \
		$(FLOAT)ft_float_a.c \
		$(FLOAT)ft_float_e.c \
		$(FLOAT)ft_float_exp_to_str.c \
		$(FLOAT)ft_float_fract_to_str.c \
		$(HANDLERS)ft_int.c \
		$(HANDLERS)ft_str.c \
		$(HANDLERS)ft_handlers.c \
		$(HANDLERS)ft_wchar.c \
		$(UTILS)utils.c \
		$(UTILS)arithmetic_utils.c \
		$(UTILS)wrapper_utils.c \
		$(UTILS)line_utils.c \
		$(UTILS)data_utils.c \
		$(UTILS)get_arg_utils_01.c \
		$(UTILS)get_arg_utils_02.c \
		$(UTILS)parse_utils_01.c \
		$(UTILS)parse_utils_02.c \
		$(UTILS)flag_utils.c \
		$(TRANSFORMS)transform_utils_01.c \
		$(TRANSFORMS)transform_utils_02.c \
		$(TRANSFORMS)transform_utils_03.c \
		$(TRANSFORMS)transform_a.c	\
		$(TRANSFORMS)transform_exp.c	\
		$(TRANSFORMS)transform_double.c

OBJ = *.o

ITALIC = \033[3m
GREEN = \033[0;32m
YELLOW = \033[1;33m
EOC = \033[0m

all: $(NAME)
$(NAME):
	@make -C ../libft/
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ) ../libft/*.o
	@echo "$(GREEN)complete:$(EOC) $(ITALIC)FT_PRINTF$(EOC)"

clean:
	@make -C ../libft/ clean
	@rm -f *.o

fclean: clean
	@make -C ../libft/ fclean
	@rm -f $(NAME) $(TEST)

re: fclean all

ret: fclean test
