#include "vm.h"

void ldi(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;
	int 			i;

	i = 1;
	if (g_bogies->its_a_highnoon != g_arena->round)
		return ;
	arg_byte = g_arena->list[g_bogies->index + i].com;
	i++;
	arg_1 = 0;
	arg_2 = 0;
	if (IS_T_IND(arg_byte, SECOND_ARG) || IS_T_IND(arg_byte, THIRD_ARG) || IS_T_DIR(arg_byte, THIRD_ARG))
	{
		skip_bytes(LDI_OP);
		return ;
	}
		if (IS_T_REG(arg_byte, FIRST_ARG))
		{
			arg_1 = get_treg(i);
			i++;
		}
		else if (IS_T_DIR(arg_byte, FIRST_ARG))
		{
			arg_1 = get_tdir_small_size(g_bogies->index + i);
			i += 2;
		}
		else
		{
			arg_1 = get_tind(0, g_bogies->index + i;
			i += 2;
		}
	if (IS_T_REG(arg_byte, SECOND_ARG))
	{
		arg_2 = get_tdir_small_size(g_bogies->index + i);
		i += 2;
	}
	else
	{
		arg_2 = get_tdir_small_size(g_bogies->index + i);
		i += 2;
	}
	arg_3 = get_tdir_small_size(g_bogies->index + i);
	i++;
	g_arena->list[g_bogies->index + (arg_1 + arg_2) % IDX_MOD].com = arg_3 / 16777216;
	g_arena->list[g_bogies->index + 1 + (arg_1 + arg_2) % IDX_MOD].com = (arg_3 % 16777216) / 65536;
	g_arena->list[g_bogies->index + 2 + (arg_1 + arg_2) % IDX_MOD].com = (arg_3 % 65536) / 256;
	g_arena->list[g_bogies->index + 3 + (arg_1 + arg_2) % IDX_MOD].com = arg_3 % 256;
	g_arena->list[g_bogies->index].bogie = 0;
	g_bogies->index = g_bogies->index + i;
	g_arena->list[g_bogies->index].bogie = 1;
	g_bogies->its_a_highnoon = 0;
}

void sti(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;
	int 			i;

	i = 1;
	if (g_bogies->its_a_highnoon != g_arena->round)
		return ;
	if (IS_T_IND(arg_byte, THIRD_ARG) || IS_T_IND(arg_byte, FIRST_ARG) || IS_T_DIR(arg_byte, FIRST_ARG))
	{
		skip_bytes(STI_OP);
		return ;
	}
	arg_byte = g_arena->list[g_bogies->index + i].com;
	i++;
	arg_2 = 0;
	arg_3 = 0;
	arg_1 = get_tdir_small_size(g_bogies->index + i);
	i ++;
	if (IS_T_REG(arg_byte, SECOND_ARG))
	{
		arg_1 = get_treg(i);
		i++;
	}
	else if (IS_T_DIR(arg_byte, SECOND_ARG))
	{
		arg_1 = get_tdir_small_size(g_bogies->index + i);
		i += 2;
	}
	else
	{
		arg_1 = get_tind(0, g_bogies->index + i);
		i += 2;
	}
	if (IS_T_REG(arg_byte, THIRD_ARG))
	{
		arg_2 = get_tdir_small_size(g_bogies->index + i);
		i += 2;
	}
	else
	{
		arg_2 = get_tdir_small_size(g_bogies->index + i);
		i += 2;
	}
	g_arena->list[g_bogies->index + (arg_3+ arg_2) % IDX_MOD].com = arg_1 / 16777216;
	g_arena->list[g_bogies->index + 1 + (arg_3 + arg_2) % IDX_MOD].com = (arg_1 % 16777216) / 65536;
	g_arena->list[g_bogies->index + 2 + (arg_3 + arg_2) % IDX_MOD].com = (arg_1 % 65536) / 256;
	g_arena->list[g_bogies->index + 3 + (arg_3 + arg_2) % IDX_MOD].com = arg_1 % 256;
	g_arena->list[g_bogies->index].bogie = 0;
	g_bogies->index = g_bogies->index + i;
	g_arena->list[g_bogies->index].bogie = 1;
	g_bogies->its_a_highnoon = 0;
}

void lldi(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;
	int 			i;

	i = 1;
	if (g_bogies->its_a_highnoon != g_arena->round)
		return ;
	arg_byte = g_arena->list[g_bogies->index + i].com;
	i++;
	arg_1 = 0;
	arg_2 = 0;
	if (IS_T_IND(arg_byte, SECOND_ARG) || IS_T_IND(arg_byte, THIRD_ARG) || IS_T_DIR(arg_byte, THIRD_ARG))
	{
		skip_bytes(LLDI_OP);
		return ;
	}
		if (IS_T_REG(arg_byte, FIRST_ARG))
		{
			arg_1 = get_treg(i);
			i++;
		}
		else if (IS_T_DIR(arg_byte, FIRST_ARG))
		{
			arg_1 = get_tdir_small_size(g_bogies->index + i);
			i += 2;
		}
		else
		{
			arg_1 = get_tind(0, g_bogies->index + i);
			i += 2;
		}
	if (IS_T_REG(arg_byte, SECOND_ARG))
	{
		arg_2 = get_tdir_small_size(g_bogies->index + i);
		i += 2;
	}
	else
	{
		arg_2 = get_tdir_small_size(g_bogies->index + i);
		i += 2;
	}
	arg_3 = get_tdir_small_size(g_bogies->index + i);
	i++;
	g_arena->list[g_bogies->index + arg_1 + arg_2].com = arg_3 / 16777216;
	g_arena->list[g_bogies->index + 1 + arg_1 + arg_2].com = (arg_3 % 16777216) / 65536;
	g_arena->list[g_bogies->index + 2 + arg_1 + arg_2].com = (arg_3 % 65536) / 256;
	g_arena->list[g_bogies->index + 3 + arg_1 + arg_2].com = arg_3 % 256;
	g_arena->list[g_bogies->index].bogie = 0;
	g_bogies->index = g_bogies->index + i;
	g_arena->list[g_bogies->index].bogie = 1;
	g_bogies->its_a_highnoon = 0;
}