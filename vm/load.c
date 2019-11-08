#include "vm.h"

void	load(void)
{
	int				arg;
	int				treg;
	unsigned char	arg_byte;

	arg_byte = g_arena->list[g_bogies->index + 1].com;
	arg = 0;
	treg = 0;
	if (IS_T_DIR(arg_byte, FIRST_ARG))
	{
		arg = get_tdir_big_size(g_bogies->index + 2);
		treg = get_treg(DIR_SIZE + 2);
	}
	else if (IS_T_IND(arg_byte, FIRST_ARG))
	{
		arg = get_tind(1, 2);
		treg = get_treg(IND_SIZE + 2);
	}
	g_bogies->regs[treg] = arg;
	g_bogies->carry = ((arg == 0) ? 1 : 0);
	g_arena->list[g_bogies->index].bogie = 0;
	g_bogies->index = g_bogies->index + DIR_SIZE + 3;
	g_arena->list[g_bogies->index].bogie = 1;
	g_bogies->its_a_highnoon = 0;
}
