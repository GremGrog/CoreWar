#include "vm.h"

void	subtraction(void)
{
	unsigned char	arg_byte;
	int				reg;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	if (IS_T_REG(arg_byte, FIRST_ARG) && IS_T_REG(arg_byte, SECOND_ARG) &&
		IS_T_REG(arg_byte, THIRD_ARG))
	{
		reg = arg_byte + 2;
		if (reg >= 16)
		{
			skip_bytes(SUB_OP);
			return ;
		}
		g_bogies->regs[arg_byte + 2] = g_bogies->regs[arg_byte] - \
												g_bogies->regs[arg_byte + 1];
		if (g_bogies->regs[arg_byte + 2] == 0)
			g_bogies->carry = 1;
		else
			g_bogies->carry = 0;
		g_bogies->aim = 3;
		if (g_flags->v == 1 || g_flags->v == 30)
			ft_printf("P %d | sub r%d r%d r%d %d\n", g_bogies->num, arg_byte, arg_byte + 1, arg_byte + 2, \
			g_bogies->regs[arg_byte + 2]);
		move_caret(g_bogies->aim);
	}
	else
	{
		skip_bytes(SUB_OP);
		return ;
	}
}
