COREWAR = corewar

LIB = make -C ft_printf

FLAGS = -Wall -Wextra -Werror -g

COREWAR_DIR_O = corewar_obj

INCLUDES =  vm.h

LIBFT = ft_printf/libftprintf.a

COREWAR_SRCS =	error_work.c \
				vm.c \
				parse_bytecode.c \
				tools.c \

COREWAR_OBJF = $(addprefix $(COREWAR_DIR_O)/, $(patsubst %.c,%.o,$(COREWAR_SRCS)))

all: $(LIB) $(COREWAR)

$(COREWAR_DIR_O):
	@mkdir -p corewar_obj

$(LIB):
	@make -C ft_printf

$(COREWAR): $(COREWAR_DIR_O) $(COREWAR_OBJF) $(LIB)
	@gcc $(COREWAR_OBJF) $(LIBFT) -o $(COREWAR)

$(COREWAR_DIR_O)/%.o: %.c 
	@gcc  -I $(INCLUDES) -o $@ -c $<

clean:
	@rm -rf $(COREWAR_DIR_O)
	@make clean -C ft_printf

fclean: clean
	@rm -rf $(COREWAR)
	@make fclean -C ft_printf

re: fclean all