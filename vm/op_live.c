/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:10:26 by kbethany          #+#    #+#             */
/*   Updated: 2019/11/28 15:18:31 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		live(void)
{
	int		arg;

	if (g_flags->v == 3)
		ft_printf("Player %d (%s) is said to be alive\n",
			g_bogies->champ->index, g_bogies->champ->name);
	arg = get_tdir_big_size((g_bogies->index + 1) % MEM_SIZE);
	g_bogies->last_breath = g_arena->round;
	g_bogies->live_op++;
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | live %d\n", g_bogies->num, arg);
	if (arg >= (int)g_arena->champ_num * -1 && arg <= -1)
		g_arena->last_stand = arg * -1;
	g_arena->mortal_flip++;
	move_caret(DIR_SIZE + 1);
}

void		zjump(void)
{
	short	arg;

	arg = get_tdir_small_size((g_bogies->index + 1) % MEM_SIZE);
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | zjmp %d %s\n",
			g_bogies->num, arg, g_bogies->carry ? "OK" : "FAILED");
	arg %= IDX_MOD;
	if (g_bogies->carry)
		move_caret(arg);
	else
		move_caret(3);
}
