# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 20:52:09 by gloras-t          #+#    #+#              #
#    Updated: 2020/12/20 01:43:22 by slindgre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
TEST = t

INCLUDES = includes
FT_PRINTF = $(INCLUDES)/ft_printf
LIBFT = $(INCLUDES)/libft

LIBFTP = $(FT_PRINTF)/libftprintf.a

SRC_DIR = src
TEST_SRC_DIR = test
OBJ_SRC_DIR = obj_src
OBJ_TEST_SRC_DIR = obj_test_src

OBJ_SRC = $(addprefix $(OBJ_SRC_DIR)/, \
			comparsion_1.o \
			comparsion_2.o \
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
	@gcc $(FLAGS) -o $(NAME) $(OBJ_SRC_DIR)/main.o $(OBJ_SRC) -I $(INCLUDES) -L $(FT_PRINTF)/ -lftprintf -g
	@echo "$(GREEN)complete:$(EOC) $(ITALIC)FT_LS$(EOC)"

# make t T=<testfile_name>.o
$(TEST): $(OBJ_TEST_SRC_DIR) $(OBJ_SRC_DIR) $(LIBFTP) $(OBJ_SRC) $(OBJ_TEST_SRC_DIR)/$(T)
	@gcc -o $(TEST) $(OBJ_TEST_SRC_DIR)/$(T) $(OBJ_SRC) -I $(INCLUDES) -L $(FT_PRINTF)/ -lftprintf -g
	@echo "$(GREEN)complete:$(EOC) $(ITALIC)TEST$(EOC)"

$(OBJ_SRC_DIR):
	@mkdir $(OBJ_SRC_DIR)

$(OBJ_SRC_DIR)/%.o: $(SRC_DIR)/%.c includes/ft_ls.h includes/ft_ls_defines.h
	@gcc -c $(FLAGS) -I $(INCLUDES) -I $(LIBFT) $< -o $@ -g

$(OBJ_TEST_SRC_DIR):
	@mkdir $(OBJ_TEST_SRC_DIR)

$(OBJ_TEST_SRC_DIR)/%.o: $(TEST_SRC_DIR)/%.c includes/ft_ls.h includes/ft_ls_defines.h
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
