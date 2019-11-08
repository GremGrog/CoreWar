#include "vm.h"

void	move_caret(int steps)
{
	g_arena->list[g_bogies->index].bogie = 0;
	if (g_bogies->index += steps >= MEM_SIZE)
		g_bogies->index = (g_bogies->index + steps) % MEM_SIZE;
	else
		g_bogies->index += steps;
	g_arena->list[g_bogies->index].bogie = 1;
	g_bogies->its_a_highnoon = 0;
}
