#include "vm.h"

void	set_bogie(int tmp_index)
{
	g_arena->list[tmp_index].bogie = 0;
	g_arena->list[g_bogies->index].bogie = 1;
	g_bogies->its_a_highnoon = 0;
}

void	store(void)
{
	int				arg;
	int				treg;
	unsigned char	arg_byte;
	int				tmp_index;

	arg_byte = g_arena->list[g_bogies->index + 1].com;
	arg = 0;
	treg = 0;
	tmp_index = g_bogies->index;
	if (IS_T_REG(arg_byte, FIRST_ARG))
		treg = get_treg(1);
	if (IS_T_REG(arg_byte, SECOND_ARG))
	{
		arg = get_treg(T_REG);
		g_bogies->regs[treg] = arg;
		g_bogies->index = g_bogies->index + 2;
	}
	else if (IS_T_IND(arg_byte, SECOND_ARG))
	{
		arg = get_tind(1, T_REG);
		g_arena->list[g_bogies->index + arg].com = treg;
		g_bogies->index = g_bogies->index + 1 + IND_SIZE;
	}
	set_bogie(tmp_index);
}
