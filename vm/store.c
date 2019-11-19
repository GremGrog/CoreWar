#include "vm.h"

void	store(void)
{
	short			arg;
	int				treg;
	unsigned char	arg_byte;
	int				tmp_index;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	arg = 0;
	treg = 0;
	tmp_index = g_bogies->index;
	// if (IS_T_REG(arg_byte, FIRST_ARG))
	if ((is_treg(arg_byte, 1)) == 1)
		treg = get_treg(2);
	else
	{
		skip_bytes(ST_OP);
		return ;
	}
	if (is_treg(arg_byte, 2))
	{
		arg = get_treg(3);
		if (arg >= 6)
			skip_bytes(ST_OP);
		g_bogies->regs[treg] = arg;
		if (g_flags->v == 1 || g_flags->v == 30)
			ft_printf("P %4d | st r%d %d\n", g_bogies->num, treg + 1, arg);
		g_bogies->aim = 3;
	}
	// if (IS_T_IND(arg_byte, SECOND_ARG))
	else if (is_tind(arg_byte, 2))
	{
		arg = get_tdir_small_size(g_bogies->index + 3);
		arg %= IDX_MOD;
		print_4bytes(arg, 0, treg, 1);
		if (g_flags->v == 1 || g_flags->v == 30)
			ft_printf("P %4d | st r%d %d\n", g_bogies->num, treg + 1, arg);
		g_bogies->aim = 2 + IND_SIZE;
	}
	// else if (IS_T_REG(arg_byte, SECOND_ARG))

	else
	{
		skip_bytes(ST_OP);
		return ;
	}
	move_caret(g_bogies->aim);
}
