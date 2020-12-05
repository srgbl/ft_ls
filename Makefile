# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gloras-t <gloras-t@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 20:52:09 by gloras-t          #+#    #+#              #
#    Updated: 2020/12/06 00:20:22 by gloras-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
TEST = t

INCLUDES = includes
FT_PRINTF = $(INCLUDES)/ft_printf
LIBFTP = $(FT_PRINTF)/libftprintf.a
LIBFT = $(INCLUDES)/libft

SRC = src
TEST_SRC = test
TEST_PREFIX = test_

OBJ_SRC_DIR = obj_src
OBJ_TEST_SRC_DIR = obj_test_src

OBJ_SRC = $(addprefix $(OBJ_SRC_DIR)/, \
			utils.o \
			parse_args.o \
			path_utils.o \
			sort_list.o \
			print_dir.o \
			print_file.o)

FLAGS = -Wall -Werror -Wextra

ITALIC = \033[3m
GREEN = \033[0;32m
EOC = \033[0m

all: $(NAME)
	
$(NAME): $(OBJ_SRC_DIR) $(LIBFTP) $(OBJ_SRC_DIR)/main.o $(OBJ_SRC)
	@gcc $(FLAGS) -o $(NAME) $(OBJ_SRC_DIR)/main.o $(OBJ_SRC) -I $(INCLUDES) -I $(LIBFT) -L $(FT_PRINTF)/ -lftprintf -g
	@echo "$(GREEN)complete:$(EOC) $(ITALIC)FT_LS$(EOC)"

# make t T=<testfile_name>.o
$(TEST): $(OBJ_TEST_SRC_DIR) $(OBJ_SRC_DIR) $(OBJ_SRC) $(LIBFTP) $(OBJ_TEST_SRC_DIR)/$(T)
	@gcc -o $(TEST) $(OBJ_TEST_SRC_DIR)/$(T) $(OBJ_SRC) -I $(INCLUDES) -I $(LIBFT) -L $(FT_PRINTF)/ -lftprintf -g

$(OBJ_SRC_DIR):
	@mkdir $(OBJ_SRC_DIR)

$(OBJ_SRC_DIR)/%.o: $(SRC)/%.c includes/ft_ls.h includes/ft_ls_defines.h
	@gcc -c $(FLAGS) -I $(INCLUDES) -I $(LIBFT) $< -o $@ -g

$(OBJ_TEST_SRC_DIR):
	@mkdir $(OBJ_TEST_SRC_DIR)

$(OBJ_TEST_SRC_DIR)/%.o: $(TEST_SRC)/%.c includes/ft_ls.h includes/ft_ls.h
	@gcc -c $(FLAGS) -I $(INCLUDES) -I $(LIBFT) $< -o $@ -g

$(LIBFTP):
	@make -sC $(FT_PRINTF)

clean:
	@make -sC $(FT_PRINTF) clean
	@rm -rf $(OBJ_SRC_DIR) $(OBJ_TEST_SRC_DIR)
	
fclean: clean
	@make -sC $(FT_PRINTF) fclean
	@rm -f $(NAME) $(TEST)
	
re: fclean all
