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
	size_t	all_bogies;
	t_bogie	*tmp_bogie;

	all_bogies = count_bogies();
	while (all_bogies > 0)
	{
		tmp_bogie = g_bogies;
		while (tmp_bogie)
		{
			exec_function();
			tmp_bogie = tmp_bogie->next;
		}
		g_arena->round++;
		break ;
	}
}