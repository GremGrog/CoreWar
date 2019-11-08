#include "vm.h"

void	load(void)
{
	int				tdir;
	short			tind;
	int				treg;
	unsigned char	arg_byte;

	arg_byte = g_arena->list[g_bogies->index + 1].com;
	// arg_byte >>= 6;
	if (IS_T_DIR(arg_byte, FIRST_ARG))
		ft_printf("%x\n", arg_byte);
}