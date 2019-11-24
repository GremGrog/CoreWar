#include "vm.h"

void	store(void)
{
	short			arg;
	int				treg;
	unsigned char	arg_byte;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	arg = 0;
	treg = 0;
	if ((is_treg(arg_byte, FIRST_ARG)) == 1)
	{
		if ((treg = get_treg(2)) >= 16)
		{
			skip_bytes(ST_OP);
			return ;
		}
	}
	else
	{
			skip_bytes(ST_OP);
			return ;
	}
	if (is_treg(arg_byte, SECOND_ARG))
	{
		arg = get_treg(3);
		if (arg >= 16)
		{
			skip_bytes(ST_OP);
			return ;
		}
		g_bogies->regs[arg] = g_bogies->regs[treg];
		if (g_flags->v == 1 || g_flags->v == 30)
			ft_printf("P %4d | st r%d %d\n", g_bogies->num, treg + 1, arg + 1);
		g_bogies->aim = 3;
	}
	else if (is_tind(arg_byte, SECOND_ARG))
	{
		arg = get_tdir_small_size(g_bogies->index + 3);
		arg %= IDX_MOD;
		print_4bytes(arg, 0, treg, 1);
		if (g_flags->v == 1 || g_flags->v == 30)
			ft_printf("P %4d | st r%d %d\n", g_bogies->num, treg + 1, arg);
		g_bogies->aim = 2 + IND_SIZE;
	}
	else
	{
		skip_bytes(ST_OP);
		return ;
	}
	move_caret(g_bogies->aim + 1);
}
