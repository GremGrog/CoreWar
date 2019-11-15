#include "vm.h"

void	info_printing_cycle(WINDOW *win, size_t y, size_t i)
{
	t_champ	*tmp_champ;
	int		live_op;
	int		last_breath;

	tmp_champ = g_arena->champs;
	while (tmp_champ && i <= g_arena->champ_num)
	{
		mvwprintw(win, y, 6, "Player-%d", tmp_champ->index);
		if (tmp_champ->index == 1)
			wcolor_set(win, 1, NULL);
		else if (tmp_champ->index == 2)
			wcolor_set(win, 2, NULL);
		else if (tmp_champ->index == 3)
			wcolor_set(win, 3, NULL);
		else if (tmp_champ->index == 4)
			wcolor_set(win, 4, NULL);
		mvwprintw(win, y, 16, "%s", tmp_champ->name);
		wcolor_set(win, 6, NULL);
		live_op = search_live_in_bogie(tmp_champ->index);
		mvwprintw(win, y + 1, 8, "Live %17d", live_op);
		last_breath = search_last_breath(tmp_champ->index);
		mvwprintw(win, y + 2, 8, "Last breath %10d", last_breath);
		tmp_champ = tmp_champ->next;
		y += 4;
	}
}

void	print_info(WINDOW *win)
{
	size_t	i;
	size_t	y;

	wattron(win, A_BOLD);
	mvwprintw(win, 4, 30, "GAME INFO");
	mvwprintw(win, 7, 6, "Cycle: %d", g_arena->round);
	mvwprintw(win, 10, 6, "Cycles To Die: %d", g_arena->cycle_to_die);
	i = 1;
	y = 13;
	info_printing_cycle(win, y, i);
	wcolor_set(win, 6, NULL);

	t_bogie *tmp;
	size_t	j;
	size_t	k;
	j = 17;
	k = 0;
	tmp = g_arena->bogie_head;
	while (tmp)
	{
		mvwprintw(win, j, 6, "Bogie index %d \n", tmp->num);
		k = 0;
		j += 2;
		while (k < 16)
		{
			mvwprintw(win, j, 6, "Regnum %-15d [%x]\n", k + 1, tmp->regs[k]);
			j++;
			k++;
		}
		j += 3;
		tmp = tmp->next;
	}
	wattroff(win, A_BOLD);
	wrefresh(win);
}

void	set_arena_colors(WINDOW *win, size_t i)
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

void	print_arena(WINDOW *win)
{
	size_t	i;
	size_t	step;
	int		y;
	int		x;

	i = 0;
	step = 0;
	y = 2;
	x = 5;
	while (i < MEM_SIZE)
	{
		if (g_arena->list[i].bogie == 1)
			wcolor_set(win, 5, NULL);
		else
			set_arena_colors(win, i);
		mvwprintw(win, y, x + step, "%02x", g_arena->list[i].com);
		step += 3;
		if (i % 64 == 63)
		{
			step = 0;
			y += 1;
		}
		i++;
	}
	wrefresh(win);
}

void	print_wins(t_windows *wins)
{
	print_arena(wins->arena);
	print_info(wins->infowin);
	control_input(wins);
	wrefresh(wins->arena);
	wrefresh(wins->infowin);
	wrefresh(wins->main_win);
	refresh();
	usleep(wins->delay * 50000);
}
