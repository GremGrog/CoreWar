COREWAR = corewar

LIB = make -C libft

FLAGS = -Wall -Wextra -Werror -g

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
				operations_1.c \

COREWAR_OBJF = $(addprefix $(COREWAR_DIR_O)/, $(patsubst %.c,%.o,$(COREWAR_SRCS)))

all: $(LIB) $(COREWAR)

$(COREWAR_DIR_O):
	@mkdir -p corewar_obj

$(LIB):
	@make -C libft

$(COREWAR): $(COREWAR_DIR_O) $(COREWAR_OBJF) $(LIB)
	@gcc $(COREWAR_OBJF) $(LIBFT) -o $(COREWAR)

$(COREWAR_DIR_O)/%.o: %.c 
	@gcc  -I $(INCLUDES) -o $@ -c $<

clean:
	@rm -rf $(COREWAR_DIR_O)
	@make clean -C libft

fclean: clean
	@rm -rf $(COREWAR)
	@make fclean -C libft

re: fclean all