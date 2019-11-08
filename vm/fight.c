#include "vm.h"

size_t	count_bogies(void)
{
	t_bogie	*tmp;
	size_t	c;

	c = 0;
	tmp = g_bogies;
	while(tmp)
	{
		tmp = tmp->next;
		c++;
	}
	return (c);
}

void	exec_function(void)
{
	if (g_bogies->commmand == g_op[1].code)
		load();
}

void	fight(void)
{
	t_bogie	*tmp_bogie;

	g_arena->all_bogies = count_bogies();
	tmp_bogie = g_bogies;
	while (g_arena->all_bogies > 0)
	{
		g_bogies = tmp_bogie;
		while (g_bogies)
		{
			exec_function();
			g_bogies = g_bogies->next;
		}
		g_arena->round++;
		break ;
	}
	battlefield_print();
}