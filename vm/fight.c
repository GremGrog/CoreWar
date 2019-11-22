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
	else if (g_bogies->commmand == g_op[10].code)
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

void	get_data_for_bogie(int current)
{
	g_bogies->commmand = g_arena->list[g_bogies->index].com;
	g_bogies->its_a_highnoon = define_cycles_to_exec(g_bogies->commmand) + current;
	g_bogies->color =  g_arena->list[g_bogies->index].color;
	if (g_bogies->color == 'g')
		g_bogies->champ->index = 1;
	if (g_bogies->color == 'r')
		g_bogies->champ->index = 2;
	if (g_bogies->color == 'y')
		g_bogies->champ->index = 3;
	if (g_bogies->color == 'b')
		g_bogies->champ->index = 4;
}

 void	lives_check(void)
 {
 	size_t	all_live_ops;
 	t_bogie	*tmp_bogie;
 	t_bogie *delta;

 	tmp_bogie = g_arena->bogie_head;
 	while (tmp_bogie)
	{
 		if (g_arena->round - tmp_bogie->last_breath >= g_arena->cycle_to_die)
		 {
			 if (g_flags->v == 30)
			 	ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", tmp_bogie->num, g_arena->round - tmp_bogie->last_breath, g_arena->cycle_to_die);
			tmp_bogie = delete_bogie(tmp_bogie);
		 }
 		else
		{
			tmp_bogie->live_op = 0;
 			tmp_bogie = tmp_bogie->next;
		}
	}
 	if (g_arena->mortal_flip >= NBR_LIVE)
	{
		g_arena->cycle_to_die -= CYCLE_DELTA;
		if (g_flags->v == 2)
			ft_printf("Cycle to die is now %d\n", g_arena->cycle_to_die);
		g_arena->death_gaze = 0;
	}
 	else
	 	g_arena->death_gaze++;
	if (g_arena->death_gaze >= MAX_CHECKS)
	{
		g_arena->cycle_to_die -= CYCLE_DELTA;
		if (g_flags->v == 2)
			ft_printf("Cycle to die is now %d\n", g_arena->cycle_to_die);
		g_arena->death_gaze = 0;
	}
	g_arena->mortal_flip = 0;
 	g_arena->doomsday_clock = 0;
 }

void	fight(void)
{
	t_bogie	*tmp_bogie;
	t_windows	*wins;
	int	c;

	c = 0;
	g_arena->all_bogies = count_bogies();
	g_arena->bogie_head = g_bogies;
	g_arena->cycle_to_die = CYCLE_TO_DIE;
	if (g_flags->i == 1)
		wins = init_w();
	while (g_arena->all_bogies > 0)
	{
		if ((g_flags->v == 2 || g_flags->v == 30) && g_arena->round > 0)
			ft_printf("It is now cycle %d\n", g_arena->round);
		g_bogies = g_arena->bogie_head;
		while (g_bogies)
		{
			if (g_arena->round == 0)
				get_data_for_bogie(g_arena->round);
			if (g_bogies->its_a_highnoon == g_arena->round)
			{
				if (g_bogies->commmand != g_arena->list[g_bogies->index].com)
					get_data_for_bogie(g_arena->round - 1);
				else
				{
					exec_function();
					get_data_for_bogie(g_arena->round);
				}
			}
			g_bogies = g_bogies->next;
		}
		if (g_arena->doomsday_clock == g_arena->cycle_to_die)
			lives_check();
		if (g_flags->i == 1)
			print_wins(wins);
		g_arena->round++;
		g_arena->doomsday_clock++;
	}
	if (g_flags->i == 1)
		delete_windows(wins);
}
