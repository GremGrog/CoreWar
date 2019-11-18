#include "vm.h"

void live(void)
{
	int				arg;

	if (g_bogies->its_a_highnoon != g_arena->round)
		return ;
	if (g_flags->v == 3)
		ft_printf("Player %d (%s) is said to be alive\n", g_bogies->champ->index, g_bogies->champ->name);
	arg = get_tdir_big_size(g_bogies->index + 1);
	g_bogies->last_breath = g_arena->round;
	g_bogies->live_op++;
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("live %d\n", arg);
	if (arg >= g_arena->champ_num * -1  && arg <= -1)
		g_arena->last_stand = arg;
	g_arena->mortal_flip++;
	move_caret(DIR_SIZE);
}

void zjump(void)
{
	int				arg;
	unsigned char	arg_byte;

	if (g_bogies->its_a_highnoon != g_arena->round)
		return;
	arg = get_tdir_small_size(g_bogies->index + 1);
	arg %= IDX_MOD;
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("zjmp %d %s\n", arg, g_bogies->carry ? "SUCCESS" : "FAILED");
	if (g_bogies->carry)
		move_caret(arg - 1);
	else
		move_caret(2);
}
