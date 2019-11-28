/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_lfork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:15:28 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 13:16:22 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	long_fork(void)
{
	short			arg;
	t_bogie			*new;

	arg = get_tdir_small_size((g_bogies->index + 1) % MEM_SIZE);
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | lfork %d (%d)\n", \
								g_bogies->num, arg, g_bogies->index + arg);
	new = create_bogie(g_bogies->champ->index);
	g_arena->all_bogies++;
	g_arena->max_bogie_num++;
	copy_bogie(new, g_bogies);
	g_arena->list[(g_bogies->index + arg) % MEM_SIZE].bogie = 1;
	new->index = (g_bogies->index + arg) % MEM_SIZE;
	new->num = g_arena->max_bogie_num;
	new->next = g_bogies->next;
	new->its_a_highnoon = 0;
	new->next = g_arena->bogie_head;
	g_arena->bogie_head = new;
	g_bogies->aim = 2;
	move_caret(g_bogies->aim + 1);
}

void	ft_fork(void)
{
	short			arg;
	t_bogie			*new;

	arg = get_tdir_small_size((g_bogies->index + 1) % MEM_SIZE);
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | fork %d (%d)\n", \
						g_bogies->num, arg, (g_bogies->index + arg % IDX_MOD));
	arg %= IDX_MOD;
	new = create_bogie(g_bogies->champ->index);
	g_arena->all_bogies++;
	g_arena->max_bogie_num++;
	copy_bogie(new, g_bogies);
	g_arena->list[(g_bogies->index + arg) % MEM_SIZE].bogie = 1;
	new->num = g_arena->max_bogie_num;
	new->index = (g_bogies->index + arg) % MEM_SIZE;
	new->its_a_highnoon = 0;
	new->next = g_arena->bogie_head;
	g_arena->bogie_head = new;
	g_bogies->aim = 2;
	move_caret(g_bogies->aim + 1);
}
