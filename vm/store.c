#include "vm.h"

void	store(void)
{
	int				arg;
	int				treg;
	unsigned char	arg_byte;
	int				tmp_index;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	arg = 0;
	treg = 0;
	tmp_index = g_bogies->index;
	if (IS_T_REG(arg_byte, FIRST_ARG))
		treg = get_treg(1);
	else
	{
		skip_bytes(ST_OP);
		return ;
	}
	if (IS_T_REG(arg_byte, SECOND_ARG))
	{
		arg = get_treg(T_REG);
		if (arg >= 6)
			skip_bytes(ST_OP);
		g_bogies->regs[treg] = arg;
		if (g_flags->v == 1 || g_flags->v == 30)
			ft_printf("P %d | st r%d r%d\n", g_bogies->num, treg, arg);
		g_bogies->aim = 2;
	}
	else if (IS_T_IND(arg_byte, SECOND_ARG))
	{
		arg = get_tind(1, T_REG);
		g_arena->list[(g_bogies->index + arg) % MEM_SIZE].com = treg;
		if (g_flags->v == 1 || g_flags->v == 30)
			ft_printf("P %d | st r%d %d\n", g_bogies->num, treg, arg);
		g_bogies->aim = 1 + IND_SIZE;
	}
	else
	{
		skip_bytes(ST_OP);
		return ;
	}
	move_caret(g_bogies->aim);
}
