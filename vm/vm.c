/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:15:43 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 15:16:00 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int c, char **a)
{
	t_champ		*champs;
	t_champ		*tmp;
	size_t		champs_num;

	if (c < 2)
		return (ft_errno(0));
	champs = NULL;
	champs = parse_args(c, a);
	if (champs != NULL)
	{
		tmp = champs;
		champs_num = count_champs(tmp);
		init_battlefield(champs, champs_num);
		add_bogies_on_arena();
		introduce_champs();
		fight();
		if (g_flags->dump == 0 || g_arena->round < g_flags->dump)
			introduce_winner();
		free(g_arena);
		delete_champs(champs);
	}
	free(g_flags);
	return (0);
}
