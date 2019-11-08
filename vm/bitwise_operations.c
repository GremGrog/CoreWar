#include "vm.h"

int		get_arg(int *arg, int position, unsigned char arg_byte)
{
	if (IS_T_REG(arg_byte, position))
	{
		*arg = g_bogies->regs[arg_byte + 2];
		return (1);
	}
	if (IS_T_DIR(arg_byte, position))
	{
		*arg = get_tdir_big_size(g_bogies->index + 1);
		return (1 + DIR_SIZE);
	}
	if (IS_T_IND(arg_byte, position))
	{
		*arg = get_tind(1, DIR_SIZE + 1);
		return (DIR_SIZE + 1);
	}
	*arg = -1;
	return (0);
}

void	bitwise_and(void)
{
	unsigned char	arg_byte;
	int				jump_i;
	int				arg1;
	int				arg2;

	arg1 = 0;
	arg2 = 0;
	arg_byte = g_arena->list[g_bogies->index + 1].com;
	jump_i = get_arg(&arg1, FIRST_ARG, arg_byte);
	jump_i += get_arg(&arg2, SECOND_ARG, arg_byte);
	if ((g_bogies->regs[++jump_i] = arg1 & arg2) == 0)
		g_bogies->carry = 1;
	else
		g_bogies->carry = 0;
	g_arena->list[g_bogies->index].bogie = 0;
	g_bogies->index += jump_i;
	g_arena->list[g_bogies->index].bogie = 1;
}

void	bitwise_or(void)
{
	unsigned char	arg_byte;
	int				jump_i;
	int				arg1;
	int				arg2;

	arg1 = 0;
	arg2 = 0;
	arg_byte = g_arena->list[g_bogies->index + 1].com;
	jump_i = get_arg(&arg1, FIRST_ARG, arg_byte);
	jump_i += get_arg(&arg2, SECOND_ARG, arg_byte);
	if ((g_bogies->regs[++jump_i] = arg1 | arg2) == 0)
		g_bogies->carry = 1;
	else
		g_bogies->carry = 0;
	g_arena->list[g_bogies->index].bogie = 0;
	g_bogies->index += jump_i;
	g_arena->list[g_bogies->index].bogie = 1;
}

void	bitwise_xor(void)
{
	unsigned char	arg_byte;
	int				jump_i;
	int				arg1;
	int				arg2;

	arg1 = 0;
	arg2 = 0;
	arg_byte = g_arena->list[g_bogies->index + 1].com;
	jump_i = get_arg(&arg1, FIRST_ARG, arg_byte);
	jump_i += get_arg(&arg2, SECOND_ARG, arg_byte);
	if ((g_bogies->regs[++jump_i] = arg1 ^ arg2) == 0)
		g_bogies->carry = 1;
	else
		g_bogies->carry = 0;
	g_arena->list[g_bogies->index].bogie = 0;
	g_bogies->index += jump_i;
	g_arena->list[g_bogies->index].bogie = 1;
}