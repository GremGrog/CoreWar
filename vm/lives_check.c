/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lives_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:14:27 by kbethany          #+#    #+#             */
/*   Updated: 2019/11/28 15:23:54 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		check_bogies(void)
{
	t_bogie	*tmp_bogie;

	tmp_bogie = g_arena->bogie_head;
	while (tmp_bogie)
	{
		if ((int)(g_arena->round - tmp_bogie->last_breath)
		>= g_arena->cycle_to_die
			|| g_arena->cycle_to_die <= 0)
		{
			if (g_flags->v == 30)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", \
tmp_bogie->num, g_arena->round - tmp_bogie->last_breath, g_arena->cycle_to_die);
			tmp_bogie = delete_bogie(tmp_bogie);
		}
		else
		{
			tmp_bogie->live_op = 0;
			tmp_bogie = tmp_bogie->next;
		}
	}
}

void		lives_check(void)
{
	check_bogies();
	if (g_arena->mortal_flip >= NBR_LIVE)
	{
		g_arena->cycle_to_die -= CYCLE_DELTA;
		if (g_flags->v == 2 || g_flags->v == 30)
			ft_printf("Cycle to die is now %d\n", g_arena->cycle_to_die);
		g_arena->death_gaze = 0;
	}
	else
		g_arena->death_gaze++;
	if (g_arena->death_gaze >= MAX_CHECKS)
	{
		g_arena->cycle_to_die -= CYCLE_DELTA;
		if (g_flags->v == 2 || g_flags->v == 30)
			ft_printf("Cycle to die is now %d\n", g_arena->cycle_to_die);
		g_arena->death_gaze = 0;
	}
	g_arena->mortal_flip = 0;
	g_arena->doomsday_clock = 0;
}
