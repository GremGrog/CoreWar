#include "vm.h"

void live(void)
{
	int				arg;

	if (g_bogies->its_a_highnoon != g_arena->round)
		return ;
	arg = get_tdir_big_size(g_bogies->index + 1);
	g_bogies->last_breath = g_arena->round;
	if (arg >= g_arena->champ_num * -1  && arg <= -1)
		g_arena->last_stand = arg;
	g_arena->list[g_bogies->index].bogie = 0;
	g_bogies->index = g_bogies->index + DIR_SIZE;
	g_arena->list[g_bogies->index].bogie = 1;
	g_bogies->its_a_highnoon = 0;
}

void zjump(void)
{
	int				arg;
	unsigned char	arg_byte;

	if (g_bogies->its_a_highnoon != g_arena->round)
		return;
	if (g_bogies->carry)
	{
		arg = get_tdir_small_size(g_bogies->index + 1);
		g_arena->list[g_bogies->index].bogie = 0;
		g_bogies->index = g_bogies->index + (arg % IDX_MOD);
		g_arena->list[g_bogies->index].bogie = 1;
		g_bogies->its_a_highnoon = 0;
	}
	else
	{
		g_arena->list[g_bogies->index].bogie = 0;
		g_bogies->index = g_bogies->index + DIR_SIZE;
		g_arena->list[g_bogies->index].bogie = 1;
		g_bogies->its_a_highnoon = 0;
	}
}