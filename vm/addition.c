#include "vm.h"

void	addition(void)
{
	unsigned char	arg_byte;

	arg_byte = g_arena->list[g_bogies->index + 1].com;
	if (IS_T_REG(arg_byte, FIRST_ARG) && IS_T_REG(arg_byte, SECOND_ARG) &&
		IS_T_REG(arg_byte, THIRD_ARG))
	{
		g_bogies->regs[arg_byte + 2] = g_bogies->regs[arg_byte] + \
												g_bogies->regs[arg_byte + 1];
		if (g_bogies->regs[arg_byte + 2] == 0)
			g_bogies->carry = 1;
		else
			g_bogies->carry = 0;
		g_bogies->aim = 3;
		move_caret(g_bogies->aim);
	}
	else
		scip_bytes(ADD_OP);
}
