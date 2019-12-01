# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsanta <vsanta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/01 15:36:59 by vsanta            #+#    #+#              #
#    Updated: 2019/12/01 15:52:38 by vsanta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= corewar

NAME_LIB 			= libft/libft.a

HEADER_NAME_MAIN	= corewar.h
HEADER_NAME_OP		= op.h
HEADER_NAME_VM		= vm.h

INC_DIR_MIAN 		= ../includes/
INC_DIR_VM 			= ./includes/
INC_DIR_LIB_FT 		= ./libft/

SRC_DIR 			= ./src/
OBJ_DIR 			= ./obj/

SRC_NAME			= add_bogies.c champs.c init_windows.c store.c \
					add_champs.c champs_tools.c introduce.c subtraction.c \
					addition.c check_file_name.c ldi_sti.c tools.c \
					aff.c define_cycles_to_exec.c lives_check.c visualisator.c \
					arena.c error_work.c load_lload.c visualisator_searching_funs.c \
					args_parser.c fight.c move_caret.c vm.c \
					bitwise_operations.c fork_lfork.c op_live.c what_is_it.c \
					bogie.c get_data.c print_4bytes.c \
					bytecode_parser.c init_flags.c print_ldi_sti.c

HEADER_MAIN 		= $(addprefix $(INC_DIR_MIAN), $(HEADER_NAME_MAIN))
HEADER_OP 			= $(addprefix $(INC_DIR_MIAN), $(HEADER_NAME_OP))
HEADER_VM 			= $(addprefix $(INC_DIR_VM), $(HEADER_NAME_VM))

SRC					= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ					= $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

CC					= gcc
FLAGS				= -Wall -Wextra -Werror
GCC_LIBFT 			= -L ./libft -l ft
GCC_INCLUDES		= -I $(INC_DIR_MIAN) -I $(INC_DIR_VM) -I $(INC_DIR_LIB_FT)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ) $(NAME_LIB)
	$(CC) $(GCC_LIBFT) $(GCC_INCLUDES) $(OBJ) $(FLAGS) -o $(NAME) -lncurses

$(OBJ_DIR):
	@mkdir -p obj

$(NAME_LIB):
	@make -C libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER_MAIN) $(HEADER_OP) $(HEADER_VM)
	$(CC) -c $(GCC_INCLUDES) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)
	@make clean -C libft/

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C libft/

re: fclean all
