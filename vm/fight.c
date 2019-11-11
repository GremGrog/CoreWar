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
	if (g_bogies->commmand != g_arena->list[g_bogies->index].com 
		|| g_bogies->its_a_highnoon == 0)
	{
		g_bogies->commmand = g_arena->list[g_bogies->index].com;
		g_bogies->its_a_highnoon = define_cycles_to_exec(g_bogies->commmand) + current;
	}
}

void	print_nc(void)
{
	size_t i;

	i = 0;
	while (i < MEM_SIZE)
	{
		// if (g_arena->list[i].bogie == 1)
		// 	ft_printf(" \x1b[46m%{black}02x", g_arena->list[i].com);
		// else
		// {
			 printw(" %02x", g_arena->list[i].com);
			// if (g_arena->list[i].color == 'g')
			// 	ft_printf(" %{green}02x", g_arena->list[i].com);
			// if (g_arena->list[i].color == 'r')
			// 	ft_printf(" %{red}02x", g_arena->list[i].com);
			// if (g_arena->list[i].color == 'y')
			// 	ft_printf(" %{yellow}02x", g_arena->list[i].com);
			// if (g_arena->list[i].color == 'b')
			// 	ft_printf(" %{blue}02x", g_arena->list[i].com);
			// if (g_arena->list[i].color == 'e')
			// 	ft_printf(" %{grey}02x", g_arena->list[i].com);
				// ft_printf(" %02x", field->list[i].com);
		// }

		i++;
	}
}

void	fight(void)
{
	t_bogie	*tmp_bogie;
	int	c;
	c = 0;
	g_arena->all_bogies = count_bogies();
	tmp_bogie = g_bogies;
	initscr();
	while (g_arena->round < 100)
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
	print_nc();
	refresh();
		getch();
	endwin();
	// battlefield_print();
}