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
	if (g_bogies->commmand == g_op[4].code)
		subtraction();
	if (g_bogies->commmand == g_op[5].code)
		bitwise_and();
	if (g_bogies->commmand == g_op[6].code)
		bitwise_or();
	if (g_bogies->commmand == g_op[7].code)
		bitwise_xor();
	if (g_bogies->commmand == g_op[8].code)
		zjump();
	if (g_bogies->commmand == g_op[9].code)
		ldi();
	if (g_bogies->commmand == g_op[10].code)
		sti();
	if (g_bogies->commmand == g_op[11].code)
		ft_fork();
	if (g_bogies->commmand == g_op[12].code)
		long_load();
	if (g_bogies->commmand == g_op[13].code)
		lldi();
	if (g_bogies->commmand == g_op[14].code)
		long_fork();
	if (g_bogies->commmand == g_op[15].code)
		aff();
	else
		move_caret(1);
}

void	get_data_for_bogie(int current)
{
	g_bogies->commmand = g_arena->list[g_bogies->index].com;
	g_bogies->its_a_highnoon = define_cycles_to_exec(g_bogies->commmand) + current;
	g_bogies->color =  g_arena->list[g_bogies->index].color;
}

// void	lives_check(void)
// {
// 	size_t	all_live_ops;
// 	t_bogie	*tmp_bogie;

// 	tmp_bogie = g_bogies;
// 	all_live_ops = 0;
// 	while (tmp_bogie)
// 	{
// 		if (tmp_bogie->last_breath <= g_arena->round )
// 		all_live_ops += tmp_bogie->live_op;
// 		tmp_bogie = tmp_bogie->next;
// 	}
// }

void	fight(t_champ *champs)
{
	t_bogie	*tmp_bogie;
	WINDOW	*win;
	int	c;
	c = 0;
	g_arena->all_bogies = count_bogies();
	g_arena->bogie_head = g_bogies;
	win = init_w(champs);
	while (g_arena->all_bogies > 0)
	{
		g_bogies = g_arena->bogie_head;
		// if (g_arena->doomsday_clock == g_arena->cycle_to_die)
		// 	lives_check();
		while (g_bogies)
		{
			if (g_arena->round == 0)
				get_data_for_bogie(g_arena->round);
			if (g_bogies->its_a_highnoon == g_arena->round)
			{
				exec_function();
				get_data_for_bogie(g_arena->round);
			}
			g_bogies = g_bogies->next;
		}
		// print_arena(win);
		// control_input(win);
		g_arena->round++;
		g_arena->doomsday_clock++;
	}
	// getch();
	delwin(win);
	endwin();
	// battlefield_print();
}