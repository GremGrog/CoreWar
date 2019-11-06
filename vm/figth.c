#include "vm.h"

void	fight(t_coliseum *arena, t_bogie *bogies)
{
	size_t	all_bogies;
	t_bogie	*tmp;

	all_bogies = 0;
	while (all_bogies > 0)
	{
		bogies = tmp;
		while (tmp)
		{
			exec_function();
			tmp = tmp->next;
		}
		arena->round++;
	}
}