#include "vm.h"

void	init_colors(WINDOW *win)
{
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_CYAN);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	wrefresh(win);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	if (can_change_color())
		init_color(COLOR_MAGENTA, 444, 444, 444);
}

void	print_info(WINDOW *win)
{
	int		y;
	int		x;

	// y = 10;
	// x = 200;
	// tmp = champs;
	// while (tmp)
	// {
	// 	mvprintw(y, x, "%s", tmp->name);
	// 	y++;
	// 	tmp = tmp->next;
	// }
	mvwprintw(win, 10, 10, "Cycle: %d", g_arena->round);
	wrefresh(win);
}

void	print_arena(WINDOW *win)
{
	size_t	i;
	size_t	step;
	int		y;
	int		x;

	i = 0;
	step = 0;
	y = 2;
	x = 4;
	while (i < MEM_SIZE)
	{
		if (g_arena->list[i].bogie == 1)
			wcolor_set(win, 5, NULL);
		else
		{
			if (g_arena->list[i].color == 'g')
				wcolor_set(win, 1, NULL);
			else if (g_arena->list[i].color == 'r')
				wcolor_set(win, 2, NULL);
			else if (g_arena->list[i].color == 'y')
				wcolor_set(win, 3, NULL);
			else if (g_arena->list[i].color == 'b')
				wcolor_set(win, 4, NULL);
			else if (g_arena->list[i].color == 'e')
				wcolor_set(win, 7, NULL);
		}
		mvwprintw(win, y, x + step, "%02x", g_arena->list[i].com);
		step += 3;
		if (i % 64 == 63)
		{
			step = 0;
			y += 1;
		}
		i++;
	}
	// mvwprintw(win, 10, 200, "Cycle: %d", g_arena->round);
	wrefresh(win);
}

WINDOW	*init_w(t_champ *champs)
{
	WINDOW *win;
	WINDOW *infowin;
	WINDOW *arena;

    if (!initscr())
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(1);
	}
    curs_set(0);
	win = newwin(300, 300, 0, 0);
	arena = derwin(win, 67, 200, 0, 0);
	infowin = derwin(win, 67, 60, 0, 199);
	refresh();
	noecho();
	
	wborder(arena, 0, 0, 0, 0, 0, 0, 0, 0);
	wborder(infowin, 0, 0, 0, 0, 0, 0, 0, 0);
	wrefresh(arena);
	wrefresh(infowin);
	wrefresh(win);
	init_colors(win);
	print_arena(arena);
	print_info(infowin);
	return (win);
}

void	control_input(WINDOW *win)
{
	char	ch;
	static int	delay;
	static size_t speed;

	ch = getch();
	if (ch == ' ' && delay == 0)
	{
		nodelay(stdscr, TRUE);
		halfdelay(speed);
		delay = 1;
	}
	else if (ch == ' ' && delay == 1)
	{
		delay = 0;
		nodelay(stdscr, FALSE);
		cbreak();
	}
	else if (ch == 's')
	{
		intrflush(stdscr, TRUE);
		delay = 1;
	}
	else if (ch == 'q')
	{
		speed++;
		halfdelay(speed);
	}
	else if (ch == 'w')
	{
		speed = 0;
		halfdelay(speed);
	}
}