#include "vm.h"

int	all_three(unsigned char	arg_byte, int num)
{
	int arg;

	if (IS_T_REG(arg_byte, num))
	{
		arg = get_treg(g_bogies->aim);
		g_bogies->aim++;
	}
	else if (IS_T_DIR(arg_byte, num))
	{
		arg = get_tdir_small_size(g_bogies->index + g_bogies->aim);
		g_bogies->aim += 2;
	}
	else
	{
		arg = get_tind(0, g_bogies->index + g_bogies->aim);
		g_bogies->aim += 2;
	}
	return (arg);
}

int reg_dir(unsigned char	arg_byte, int num)
{
	int arg;

	if (IS_T_REG(arg_byte, num))
	{
		arg = get_tdir_small_size(g_bogies->index + g_bogies->aim);
		g_bogies->aim += 2;
	}
	else
	{
		arg = get_tdir_small_size(g_bogies->index + g_bogies->aim);
		g_bogies->aim += 2;
	}
	return (arg);
}

void	print_4bytes(int a1, int a2, int a3, int flag_l)
{
	if (flag_l)
	{
		g_arena->list[g_bogies->index + a1 + a2].com = a3 / 16777216;
		g_arena->list[g_bogies->index + 1 + a1 + a2].com = (a3 % 16777216) / 65536;
		g_arena->list[g_bogies->index + 2 + a1 + a2].com = (a3 % 65536) / 256;
		g_arena->list[g_bogies->index + 3 + a1 + a2].com = a3 % 256;
	}
	else
	{
		g_arena->list[g_bogies->index + (a1 + a2) % IDX_MOD].com = a3 / 16777216;
		g_arena->list[g_bogies->index + 1 + (a1 + a2) % IDX_MOD].com = (a3 % 16777216) / 65536;
		g_arena->list[g_bogies->index + 2 + (a1 + a2) % IDX_MOD].com = (a3 % 65536) / 256;
		g_arena->list[g_bogies->index + 3 + (a1 + a2) % IDX_MOD].com = a3 % 256;
	}
}

void ldi(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;

	if (g_bogies->its_a_highnoon != g_arena->round)
		return ;
	arg_byte = g_arena->list[g_bogies->index + 1].com;
	g_bogies->aim = 2;
	if (IS_T_IND(arg_byte, SECOND_ARG) || IS_T_IND(arg_byte, THIRD_ARG) || IS_T_DIR(arg_byte, THIRD_ARG))
	{
		skip_bytes(LDI_OP);
		return ;
	}
	arg_1 = all_three(arg_byte, FIRST_ARG);
	arg_2 = reg_dir(arg_byte, SECOND_ARG);
	arg_3 = get_tdir_small_size(g_bogies->index + g_bogies->aim);
	g_bogies->aim++;
	print_4bytes(arg_1, arg_2, arg_3, 0);
	move_caret(g_bogies->aim);
	g_bogies->aim = 0;
}

void sti(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;

	if (g_bogies->its_a_highnoon != g_arena->round)
		return ;
	if (IS_T_IND(arg_byte, THIRD_ARG) || IS_T_IND(arg_byte, FIRST_ARG) || IS_T_DIR(arg_byte, FIRST_ARG))
	{
		skip_bytes(STI_OP);
		return ;
	}
	arg_byte = g_arena->list[g_bogies->index + 1].com;
	arg_1 = get_tdir_small_size(g_bogies->index + 2);
	g_bogies->aim = 2;
	arg_2 = all_three(arg_byte, SECOND_ARG);
	arg_3 = reg_dir(arg_byte, THIRD_ARG);
	print_4bytes(arg_2, arg_3, arg_1, 0);
	move_caret(g_bogies->aim);
	g_bogies->aim = 0;
}

void lldi(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;

	if (g_bogies->its_a_highnoon != g_arena->round)
		return ;
	arg_byte = g_arena->list[g_bogies->index + 1].com;
	arg_1 = 0;
	arg_2 = 0;
	g_bogies->aim = 2;
	if (IS_T_IND(arg_byte, SECOND_ARG) || IS_T_IND(arg_byte, THIRD_ARG) || IS_T_DIR(arg_byte, THIRD_ARG))
	{
		skip_bytes(LLDI_OP);
		return ;
	}
	arg_1 = all_three(arg_byte, FIRST_ARG);
	arg_2 = reg_dir(arg_byte, SECOND_ARG);
	arg_3 = get_tdir_small_size(g_bogies->index + g_bogies->aim);
	g_bogies->aim++;
	print_4bytes(arg_1, arg_2, arg_3, 1);
	move_caret(g_bogies->aim);
	g_bogies->aim = 0;
}