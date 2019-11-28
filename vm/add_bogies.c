/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bogies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:44:34 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 15:24:38 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add_bogies_cycle(size_t c, t_bogie *new, size_t index, size_t step)
{
	while (c <= g_arena->champ_num)
	{
		new = create_bogie(c);
		new->num = c;
		new->index = index;
		new->last_breath = 0;
		new->regs[0] = c * (-1);
		if (g_bogies == NULL)
			g_bogies = new;
		else if (g_bogies != NULL)
		{
			new->next = g_bogies;
			g_bogies = new;
		}
		g_arena->list[index].bogie = 1;
		index += step;
		c++;
	}
}

void	add_bogies_on_arena(void)
{
	size_t	index;
	t_bogie	*new;
	size_t	c;
	size_t	step;

	c = 1;
	new = NULL;
	index = 0;
	g_bogies = NULL;
	step = MEM_SIZE / g_arena->champ_num;
	add_bogies_cycle(c, new, index, step);
}
