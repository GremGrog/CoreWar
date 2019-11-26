#include "vm.h"

void	exec_function_p2(void)
{
	if (g_bogies->commmand == g_op[10].code)
		sti();
	else if (g_bogies->commmand == g_op[11].code)
		ft_fork();
	else if (g_bogies->commmand == g_op[12].code)
		long_load();
	else if (g_bogies->commmand == g_op[13].code)
		lldi();
	else if (g_bogies->commmand == g_op[14].code)
		long_fork();
	else if (g_bogies->commmand == g_op[15].code)
		aff();
	else
		move_caret(1);
}

void	exec_function(void)
{
	if (g_bogies->commmand == g_op[0].code)
		live();
	else if (g_bogies->commmand == g_op[1].code)
		load();
	else if (g_bogies->commmand == g_op[2].code)
		store();
	else if (g_bogies->commmand == g_op[3].code)
		addition();
	else if (g_bogies->commmand == g_op[4].code)
		subtraction();
	else if (g_bogies->commmand == g_op[5].code)
		bitwise_and();
	else if (g_bogies->commmand == g_op[6].code)
		bitwise_or();
	else if (g_bogies->commmand == g_op[7].code)
		bitwise_xor();
	else if (g_bogies->commmand == g_op[8].code)
		zjump();
	else if (g_bogies->commmand == g_op[9].code)
		ldi();
	else
		exec_function_p2();
}

void	get_data_for_bogie(int current)
{
	if (g_bogies->its_a_highnoon == 0)
	{
		g_bogies->commmand = g_arena->list[g_bogies->index].com;
		g_bogies->its_a_highnoon = define_cycles_to_exec(g_bogies->commmand);
		g_bogies->color =  g_arena->list[g_bogies->index].color;
	}
	if (g_bogies->its_a_highnoon > 0 && g_arena->round > 0)
		g_bogies->its_a_highnoon--;
}

void	game_cycle(t_windows *wins)
{
	while (g_arena->all_bogies > 0)
	{
		if ((g_flags->v == 2 || g_flags->v == 30) && g_arena->round > 0)
			ft_printf("It is now cycle %d\n", g_arena->round);
		g_bogies = g_arena->bogie_head;
		while (g_bogies)
		{
			get_data_for_bogie(0);	
			if (g_bogies->its_a_highnoon == 0)
				exec_function();
			g_bogies = g_bogies->next;
		}
		if (g_arena->doomsday_clock == g_arena->cycle_to_die 
		|| g_arena->cycle_to_die <= 0)
			lives_check();
		if (g_flags->i == 1)
			print_wins(wins);
		if (g_flags->dump != 0 && g_flags->dump == g_arena->round)
		{
			battlefield_print();
			break ;
		}
		g_arena->round++;
		g_arena->doomsday_clock++;
	}
}

void	fight(void)
{
	t_bogie		*tmp_bogie;
	t_windows	*wins;
	int	c;

	c = 0;
	g_arena->all_bogies = count_bogies();
	g_arena->max_bogie_num = g_arena->all_bogies;
	g_arena->bogie_head = g_bogies;
	g_arena->cycle_to_die = CYCLE_TO_DIE;
	wins = NULL;
	if (g_flags->i == 1)
		wins = init_w();
	game_cycle(wins);
	if (g_flags->i == 1)
		delete_windows(wins);
}
