COREWAR = corewar

LIB = make -C libft

FLAGS = -Wall -Wextra -Werror

COREWAR_DIR_O = corewar_obj

INCLUDES =  vm.h

LIBFT = libft/libft.a

COREWAR_SRCS =	error_work.c \
				vm.c \
				bytecode_parser.c \
				args_parser.c \
				champs.c \
				tools.c \
				arena.c \
				bogie.c \
				define_cycles_to_exec.c \
				fight.c \
				get_data.c \
				load_lload.c \
				store.c \
				addition.c \
				subtraction.c \
				bitwise_operations.c \
				op_live.c \
				move_caret.c \
				aff.c \
				fork_lfork.c \
				ldi_sti.c \
				visualisator.c \
				init_windows.c \
				visualisator_searching_funs.c \
				introduce.c \
				what_is_it.c \
				lives_check.c \
				print_4bytes.c \
				add_bogies.c \
				add_champs.c \
				champs_tools.c \
				print_ldi_sti.c \
				init_flags.c \
				check_file_name.c \

COREWAR_OBJF = $(addprefix $(COREWAR_DIR_O)/, $(patsubst %.c,%.o,$(COREWAR_SRCS)))

all: $(LIB) $(COREWAR)

$(COREWAR_DIR_O):
	@mkdir -p corewar_obj

$(LIB):
	@make -C libft

$(COREWAR): $(COREWAR_DIR_O) $(COREWAR_OBJF) $(LIB)
	gcc $(FLAGS) $(COREWAR_OBJF) $(LIBFT) -o $(COREWAR) -lncurses

$(COREWAR_DIR_O)/%.o: %.c $(INCLUDES)
	@gcc $(FLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	@rm -rf $(COREWAR_DIR_O)
	@make clean -C libft

fclean: clean
	@rm $(COREWAR)
	@make fclean -C libft

re: fclean all
