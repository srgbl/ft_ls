# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 20:52:09 by gloras-t          #+#    #+#              #
#    Updated: 2020/07/03 19:25:00 by slindgre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_LS = ft_ls
INCLUDES = includes
FT_PRINTF = $(INCLUDES)/ft_printf
LIBFTP = $(FT_PRINTF)/libftp.a
LIBFT = $(INCLUDES)/libft
OBJ_SRC_DIR = obj_src
OBJ_SRC = $(addprefix $(OBJ_SRC_DIR)/, utils.o)

FLAGS = -Wall -Werror -Wextra

ITALIC = \033[3m
GREEN = \033[0;32m
EOC = \033[0m

all: $(FT_LS)
	
$(FT_LS): $(OBJ_SRC_DIR) $(LIBFTP) $(OBJ_SRC_DIR)/main.o $(OBJ_SRC)
	@gcc $(FLAGS) -o $(FT_LS) $(OBJ_SRC_DIR)/main.o $(OBJ_SRC) -I $(INCLUDES) -I $(LIBFT) -L $(FT_PRINTF)/ -lftp -g
	@echo "$(GREEN)complete:$(EOC) $(ITALIC)FT_LS$(EOC)"

$(OBJ_SRC_DIR):
	@mkdir $(OBJ_SRC_DIR)

$(OBJ_SRC_DIR)/%.o: src/%.c includes/ft_ls.h
	@gcc -c $(FLAGS) -I $(INCLUDES) -I $(LIBFT) $< -o $@ -g

$(LIBFTP):
	@make -C $(FT_PRINTF)

clean:
	@make -C $(FT_PRINTF) clean
	@rm -rf $(OBJ_SRC_DIR)
	
fclean: clean
	@make -C $(FT_PRINTF) fclean
	@rm -f $(FT_LS)
	
re: fclean all
