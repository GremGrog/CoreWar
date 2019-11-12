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
	g_bogies->next = new;
	g_bogies->aim = 2;
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
	new->next = g_bogies->next;
	g_bogies->next = new;
	g_bogies->aim = 2;
	move_caret(g_bogies->aim);
}