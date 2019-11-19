#include "vm.h"

void	long_fork(void)
{
	short			arg;
	t_bogie			*new;

	arg = get_tdir_small_size(g_bogies->index + 1);
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %d | lfork %d \n", g_bogies->num, arg);
	new = create_bogie(g_bogies->champ->index);
	g_arena->all_bogies++;
	copy_bogie(new, g_bogies);
	g_arena->list[(g_bogies->index + arg) % MEM_SIZE].bogie = 1;
	new->index = (g_bogies->index + arg) % MEM_SIZE;
	new->next = g_bogies->next;
	new->commmand = g_arena->list[new->index].com;
	new->its_a_highnoon = define_cycles_to_exec(new->commmand) + g_arena->round;
	new->next = g_arena->bogie_head;
	g_arena->bogie_head = new;
	g_bogies->aim = 2;
	move_caret(g_bogies->aim);
}

void	ft_fork(void)
{
	short			arg;
	t_bogie			*new;

	arg = get_tdir_small_size(g_bogies->index + 1);
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %d | fork %d (%d)\n", g_bogies->num, arg, (g_bogies->index + arg) % MEM_SIZE);
	arg %= IDX_MOD;
	new = create_bogie(g_bogies->champ->index);
	g_arena->all_bogies++;
	copy_bogie(new, g_bogies);
	g_arena->list[(g_bogies->index + arg) % MEM_SIZE].bogie = 1;
	new->index = (g_bogies->index + arg) % MEM_SIZE;
	new->commmand = g_arena->list[new->index].com;
	new->its_a_highnoon = define_cycles_to_exec(new->commmand) + g_arena->round;
	new->next = g_arena->bogie_head;
	g_arena->bogie_head = new;
	g_bogies->aim = 2;
	move_caret(g_bogies->aim);
}