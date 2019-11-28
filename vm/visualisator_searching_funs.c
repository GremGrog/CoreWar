/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisator_searching_funs.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:14:08 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 15:19:34 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		search_live_in_bogie(int champ_index)
{
	t_bogie	*tmp_bogie;
	int		live_op;

	tmp_bogie = g_arena->bogie_head;
	live_op = 0;
	while (tmp_bogie)
	{
		if (tmp_bogie->champ->index == champ_index)
			live_op += tmp_bogie->live_op;
		tmp_bogie = tmp_bogie->next;
	}
	return (live_op);
}

int		search_last_breath(int champ_index)
{
	t_bogie	*tmp_bogie;

	tmp_bogie = g_arena->bogie_head;
	while (tmp_bogie)
	{
		if (tmp_bogie->champ->index == champ_index)
			return (tmp_bogie->last_breath);
		tmp_bogie = tmp_bogie->next;
	}
	return (0);
}
