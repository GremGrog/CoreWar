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
	if (g_bogies->commmand == g_op[0].code)
		live();
	if (g_bogies->commmand == g_op[1].code)
		load();
	if (g_bogies->commmand == g_op[2].code)
		store();
	if (g_bogies->commmand == g_op[3].code)
		addition();
	if (g_bogies->commmand == g_op[9].code)
		zjump();
}

void	get_data_for_bogie(int current)
{
	if (g_bogies->commmand != g_arena->list[g_bogies->index].com 
		|| g_bogies->its_a_highnoon == 0)
	{
		g_bogies->commmand = g_arena->list[g_bogies->index].com;
		g_bogies->its_a_highnoon = define_cycles_to_exec(g_bogies->commmand) + current;
	}
}

void	fight(void)
{
	t_bogie	*tmp_bogie;
	int	c;
	c = 0;
	g_arena->all_bogies = count_bogies();
	tmp_bogie = g_bogies;
	while (g_arena->round < 10)
	{
		g_bogies = tmp_bogie;
		while (g_bogies)
		{
			get_data_for_bogie(g_arena->round);
			if (g_bogies->its_a_highnoon == g_arena->round)
				exec_function();
			g_bogies = g_bogies->next;
		}
		g_arena->round++;
	}
	battlefield_print();
}