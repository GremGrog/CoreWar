#include "vm.h"

void	get_arg(int *arg, int position, unsigned char arg_byte)
{
	int	reg;

	if (is_treg(arg_byte, position))
	{
		reg = 0;
		if ((reg = get_treg(g_bogies->aim)) < 16)
		{
			g_bogies->aim++;
			*arg = g_bogies->regs[reg];
			return ;
		}
		else
			*arg = -1;
	}
	else if (is_tdir(arg_byte, position))
	{
		*arg = get_tdir_big_size(g_bogies->aim);
		g_bogies->aim += 4;
	}
	else if (is_tind(arg_byte, position))
	{
		*arg = get_tind(1, g_bogies->aim);
		g_bogies->aim += 2;
	}
}

void	bitwise_and(void)
{
	unsigned char	arg_byte;
	int				arg1;
	int				arg2;
	int				reg;

	arg1 = 0;
	arg2 = 0;
	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 2;
	get_arg(&arg1, FIRST_ARG, arg_byte);
	get_arg(&arg2, SECOND_ARG, arg_byte);
	reg = get_treg(g_bogies->aim);
	if (arg1 == -1 || arg2 == -1 || reg >= 16)
	{
		skip_bytes(arg_byte);
		return ;
	}
	if ((g_bogies->regs[reg] = arg1 & arg2) == 0)
		g_bogies->carry = 1;
	else
		g_bogies->carry = 0;
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | and %d %d r%d\n", g_bogies->num, arg1, arg2, reg + 1);
	move_caret(g_bogies->aim);
}

void	bitwise_or(void)
{
	unsigned char	arg_byte;
	int				arg1;
	int				arg2;
	int				reg;

	arg1 = 0;
	arg2 = 0;
	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 2;
	get_arg(&arg1, FIRST_ARG, arg_byte);
	get_arg(&arg2, SECOND_ARG, arg_byte);
	reg = get_treg(g_bogies->aim);
	if (arg1 == -1 || arg2 == -1 || reg >= 16)
	{
		skip_bytes(arg_byte);
		return ;
	}
	if ((g_bogies->regs[reg] = arg1 | arg2) == 0)
		g_bogies->carry = 1;
	else
		g_bogies->carry = 0;
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | or %d %d r%d\n", g_bogies->num, arg1, arg2, reg + 1);
	move_caret(g_bogies->aim);
}

void	bitwise_xor(void)
{
	unsigned char	arg_byte;
	int				arg1;
	int				arg2;
	int				reg;

	arg1 = 0;
	arg2 = 0;
	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 2;
	get_arg(&arg1, FIRST_ARG, arg_byte);
	get_arg(&arg2, SECOND_ARG, arg_byte);
	reg = get_treg(g_bogies->aim);
	if (arg1 == -1 || arg2 == -1 || reg >= 16)
	{
		skip_bytes(arg_byte);
		return ;
	}
	if ((g_bogies->regs[reg] = arg1 ^ arg2) == 0)
		g_bogies->carry = 1;
	else
		g_bogies->carry = 0;
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | xor %d %d r%d\n", g_bogies->num, arg1, arg2, reg + 1);
	move_caret(g_bogies->aim);
}
