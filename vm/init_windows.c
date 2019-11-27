/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:05:54 by kbethany          #+#    #+#             */
/*   Updated: 2019/11/26 19:14:18 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void				init_colors(WINDOW *win)
{
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_CYAN);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	wrefresh(win);
	if (can_change_color())
		init_color(COLOR_MAGENTA, 444, 444, 444);
}

void				draw_borders(t_windows *wins)
{
	size_t			i;

	i = -1;
	while (++i < 300)
	{
		wcolor_set(wins->main_win, 7, NULL);
		mvwaddch(wins->main_win, 0, i, ' ' | A_REVERSE);
		mvwaddch(wins->main_win, i, 0, ' ' | A_REVERSE);
		mvwaddch(wins->main_win, i, 200, ' ' | A_REVERSE);
		if (i < 200)
		{
			color_set(7, NULL);
			mvaddch(80, i, ' ' | A_REVERSE);
		}
	}
}

t_windows			*init_w(void)
{
	t_windows		*wins;

	if (!initscr())
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(1);
	}
	curs_set(0);
	wins = (t_windows*)malloc(sizeof(t_windows));
	wins->main_win = newwin(300, 300, 0, 0);
	wins->arena = derwin(wins->main_win, 80, 200, 0, 0);
	wins->infowin = derwin(wins->main_win, 80, 80, 0, 199);
	wins->delay = 0;
	refresh();
	noecho();
	wrefresh(wins->arena);
	wrefresh(wins->infowin);
	wrefresh(wins->main_win);
	init_colors(wins->main_win);
	wcolor_set(wins->main_win, 1, NULL);
	draw_borders(wins);
	wrefresh(wins->main_win);
	refresh();
	return (wins);
}

void				control_input(t_windows *wins)
{
	char			ch;
	static int		delay;
	static size_t	speed;

	ch = getch();
	speed = 1;
	if (ch == ' ' && delay == 0)
	{
		nodelay(stdscr, TRUE);
		delay = 1;
	}
	else if (ch == ' ' && delay == 1)
	{
		delay = 0;
		nodelay(stdscr, FALSE);
	}
	else if (ch == 'q')
		wins->delay += 1;
	else if (ch == 'w')
	{
		if (wins->delay > 0)
			wins->delay -= 1;
		else
			wins->delay = 0;
	}
}

void				delete_windows(t_windows *wins)
{
	delwin(wins->arena);
	delwin(wins->infowin);
	delwin(wins->main_win);
	free(wins);
	endwin();
}
