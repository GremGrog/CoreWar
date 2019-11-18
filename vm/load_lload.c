#include "vm.h"

void	long_load(void)
{
	unsigned int	arg;
	int				treg;
	unsigned char	arg_byte;

	arg_byte = g_arena->list[g_bogies->index + 1].com;
	arg = 0;
	treg = 0;
	if (IS_T_DIR(arg_byte, FIRST_ARG) && IS_T_REG(arg_byte, SECOND_ARG))
	{
		arg = get_tdir_big_size(g_bogies->index + 2);
		treg = get_treg(DIR_SIZE + 2);
	}
	else if (IS_T_IND(arg_byte, FIRST_ARG) && IS_T_REG(arg_byte, SECOND_ARG))
	{
		arg = get_tdir_big_size(g_bogies->index + 2);
		treg = get_treg(g_bogies->index + arg);
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
		ft_printf("P %d | lld %d r%d\n", g_bogies->num, arg, treg);
	g_bogies->aim = DIR_SIZE + 3;
	g_bogies->regs[treg] = arg;
	g_bogies->carry = ((arg == 0) ? 1 : 0);
	move_caret(g_bogies->aim);
}

void	load(void)
{
	unsigned int	arg;
	int				treg;
	unsigned char	arg_byte;

	arg_byte = g_arena->list[g_bogies->index + 1].com;
	arg = 0;
	treg = 0;
	if (IS_T_IND(arg_byte, FIRST_ARG) && IS_T_REG(arg_byte, SECOND_ARG))
	{
		arg = get_tind(1, 2);
		treg = get_treg(IND_SIZE + 2);
		g_bogies->aim = IND_SIZE + 2;
	}
	else if (IS_T_DIR(arg_byte, FIRST_ARG) && IS_T_REG(arg_byte, SECOND_ARG))
	{
		arg = get_tdir_big_size(g_bogies->index + 2);
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
		ft_printf("P %d | ld %d r%d\n", g_bogies->num, arg, treg);
	g_bogies->regs[treg] = arg;
	g_bogies->carry = ((arg == 0) ? 1 : 0);
	move_caret(g_bogies->aim);
}
