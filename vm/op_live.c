#include "vm.h"

void live(void)
{
	int				arg;
	unsigned char	arg_byte;

	if (g_bogies->its_a_highnoon != g_arena->round)
		return ;
	arg_byte = g_arena->list[g_bogies->index + 1].com;
	arg = 0;
	if (IS_T_DIR(arg_byte, FIRST_ARG))
	{
		arg = get_tdir_big_size(g_bogies->index + 2);
		g_bogies->last_breath = g_arena->round;
		if (arg >= g_arena->champ_num * -1  && arg <= -1)
			g_arena->last_stand = arg;
	}
	g_arena->list[g_bogies->index].bogie = 0;
	g_bogies->index = g_bogies->index + DIR_SIZE + 3;
	g_arena->list[g_bogies->index].bogie = 1;
	g_bogies->its_a_highnoon = 0;
}

void zjump(void)
{
	int				arg;
	unsigned char	arg_byte;

	if (g_bogies->its_a_highnoon != g_arena->round)
		return ;
	arg_byte = g_arena->list[g_bogies->index + 1].com;
	arg = 0;
	if (g_bogies->carry && IS_T_DIR(arg_byte, FIRST_ARG))
	{
		arg = get_tdir_small_size(g_bogies->index + 2);
		g_arena->list[g_bogies->index].bogie = 0;
		g_bogies->index = g_bogies->index + (arg % IDX_MOD);
		g_arena->list[g_bogies->index].bogie = 1;
		g_bogies->its_a_highnoon = 0;
	}
	else
	{
		g_arena->list[g_bogies->index].bogie = 0;
		g_bogies->index = g_bogies->index + 5;
		g_arena->list[g_bogies->index].bogie = 1;
		g_bogies->its_a_highnoon = 0;
	}
}