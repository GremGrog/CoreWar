#include "vm.h"

void	long_fork(void)
{
	short			arg;
	t_bogie			*new;

	arg = get_tdir_small_size(g_bogies->index + 1);
	new = create_bogie();
	copy_bogie(new, g_bogies);
	g_arena->list[g_bogies->index + arg].bogie = 1;
	new->index = g_bogies->index + arg;
	new->next = g_bogies->next;
	new->commmand = g_arena->list[new->index].com;
	new->its_a_highnoon = define_cycles_to_exec(new->commmand) + g_arena->round;
	new->next = g_arena->bogie_head;
	g_arena->bogie_head = new;
	g_bogies->aim = 2;
	g_arena->all_bogies++;
	move_caret(g_bogies->aim);
}

void	ft_fork(void)
{
	short			arg;
	t_bogie			*new;

	arg = get_tdir_small_size(g_bogies->index + 1);
	arg %= IDX_MOD;
	new = create_bogie();
	copy_bogie(new, g_bogies);
	g_arena->list[g_bogies->index + arg].bogie = 1;
	new->index = g_bogies->index + arg;
	new->commmand = g_arena->list[new->index].com;
	new->its_a_highnoon = define_cycles_to_exec(new->commmand) + g_arena->round;
	new->next = g_arena->bogie_head;
	g_arena->bogie_head = new;
	g_bogies->aim = 2;
	g_arena->all_bogies++;
	move_caret(g_bogies->aim);
}