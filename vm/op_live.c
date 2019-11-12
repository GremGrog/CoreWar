#include "vm.h"

void live(void)
{
	int				arg;

	if (g_bogies->its_a_highnoon != g_arena->round)
		return ;
	arg = get_tdir_big_size(g_bogies->index + 1);
	g_bogies->last_breath = g_arena->round;
	g_bogies->live_op++;
	if (arg >= g_arena->champ_num * -1  && arg <= -1)
		g_arena->last_stand = arg;
	move_caret(DIR_SIZE);
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
		arg %= IDX_MOD;
		move_caret(arg - 1);
	}
	else
		move_caret(2);
}
