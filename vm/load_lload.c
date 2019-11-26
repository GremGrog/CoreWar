#include "vm.h"

void	long_load(void)
{
	unsigned int	arg;
	int				treg;
	unsigned char	arg_byte;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	arg = 0;
	treg = 0;
	if (is_tdir(arg_byte, FIRST_ARG) && is_treg(arg_byte, SECOND_ARG))
	{
		arg = get_tdir_big_size((g_bogies->index + 2) % MEM_SIZE);
		treg = get_treg(DIR_SIZE + 2);
		g_bogies->aim = 1 + 4 + 1;
	}
	else if (is_tind(arg_byte, FIRST_ARG) && is_treg(arg_byte, SECOND_ARG))
	{
		arg = get_tind(1, 2);
		treg = get_treg(4);
		g_bogies->aim = 1 + 2 + 1;
	}
	else
	{
		skip_bytes(LLD_OP);
		return ;
	}
	if (treg >= 16)
	{
		skip_bytes(LLD_OP);
		return ;
	}
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | lld %d r%d\n", g_bogies->num, arg, treg + 1);
	g_bogies->regs[treg] = arg;
	g_bogies->carry = ((arg == 0) ? 1 : 0);
	move_caret(g_bogies->aim + 1);
}

void	load(void)
{
	unsigned int	arg;
	int				treg;
	unsigned char	arg_byte;


	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	arg = 0;
	treg = 0;
	if (is_tind(arg_byte, FIRST_ARG) && is_treg(arg_byte, SECOND_ARG))
	{
		arg = get_tind(1, 2);
		treg = get_treg(IND_SIZE + 2);
		g_bogies->aim = IND_SIZE + 2;
	}
	else if (is_tdir(arg_byte, FIRST_ARG) && is_treg(arg_byte, SECOND_ARG))
	{
		arg = get_tdir_big_size((g_bogies->index + 2) % MEM_SIZE);
		treg = get_treg(DIR_SIZE + 2);
		g_bogies->aim = DIR_SIZE + 2;
	}
	else
	{
		skip_bytes(LD_OP);
		return ;
	}
	if (treg >= 16)
	{
		skip_bytes(LD_OP);
		return ;
	}
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | ld %d r%d\n", g_bogies->num, arg, treg + 1);
	g_bogies->regs[treg] = arg;
	g_bogies->carry = ((arg == 0) ? 1 : 0);
	move_caret(g_bogies->aim + 1);
}
