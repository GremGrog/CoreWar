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

// void	print_info(WINDOW *win, t_champ *champs)
// {
// 	t_champ	*tmp;
// 	int		y;
// 	int		x;

// 	y = 10;
// 	x = 200;
// 	tmp = champs;
// 	while (tmp)
// 	{
// 		mvprintw(y, x, "%s", tmp->name);
// 		y++;
// 		tmp = tmp->next;
// 	}
// }

void	print_arena(WINDOW *win)
{
	size_t	i;
	size_t	step;
	int		y;
	int		x;

	i = 0;
	step = 0;
	y = 2;
	x = 2;
	while (i < MEM_SIZE)
	{
		if (g_arena->list[i].bogie == 1)
			color_set(5, NULL);
		else
		{
			if (g_arena->list[i].color == 'g')
				color_set(1, NULL);
			else if (g_arena->list[i].color == 'r')
				color_set(2, NULL);
			else if (g_arena->list[i].color == 'y')
				color_set(3, NULL);
			else if (g_arena->list[i].color == 'b')
				color_set(4, NULL);
			else
				color_set(6, NULL);
		}
		mvprintw(y, x + step, "%02x", g_arena->list[i].com);
		step += 3;
		if (i % 64 == 63)
		{
			step = 0;
			y += 1;
		}
		i++;
	}
	mvprintw(10, 200, "Cycle: %d", g_arena->round);
}


WINDOW	*init_w(t_champ *champs)
{
	WINDOW *win;

    if (!initscr())
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
	}
	initscr();
    curs_set(0);
    refresh();
	win = newwin(LINES, COLS - (COLS / 100) * 30, 0, 0);
    // wborder(win, 0, 0, 0, 0, 0,0,0,0);
	// wrefresh(win);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_CYAN);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	// print_arena(win);
	// wrefresh(win);
	// getch();
	// delwin(win);
	// endwin();
	return (win);
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


void	fight(t_champ *champs)
{
	t_bogie	*tmp_bogie;
	WINDOW	*win;
	int	c;
	c = 0;
	g_arena->all_bogies = count_bogies();
	tmp_bogie = g_bogies;
	win = init_w(champs);
	while (g_arena->all_bogies > 0)
	{
		g_bogies = tmp_bogie;
		// if (g_arena->round == CYCLE_TO_DIE)
		while (g_bogies)
		{
			if (g_bogies->its_a_highnoon == g_arena->round)
			{
				exec_function();
				get_data_for_bogie(g_arena->round);
			}
			print_arena(win);
			getch();
			g_bogies = g_bogies->next;
		}
		g_arena->round++;
	}
	// getch();
	delwin(win);
	endwin();
	// battlefield_print();
}