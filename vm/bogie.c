/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bogie.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:31:35 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 15:25:08 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		copy_bogie(t_bogie *new, t_bogie *bogie)
{
	size_t	i;

	i = 0;
	new->carry = bogie->carry;
	new->champ = bogie->champ;
	new->last_breath = bogie->last_breath;
	while (i < REG_NUMBER)
	{
		new->regs[i] = bogie->regs[i];
		i++;
	}
	new->next = bogie->next;
}

t_bogie		*create_bogie(size_t c)
{
	t_bogie	*bogie;
	t_champ *tmp;
	size_t	i;

	bogie = (t_bogie*)malloc(sizeof(t_bogie));
	bogie->num = -1;
	bogie->carry = 0;
	bogie->commmand = 0;
	bogie->last_breath = 0;
	bogie->its_a_highnoon = 0;
	bogie->index = 0;
	bogie->aim = 0;
	bogie->color = 0;
	bogie->live_op = 0;
	bogie->regs = (unsigned int*)malloc(sizeof(unsigned int) * REG_NUMBER);
	bogie->next = NULL;
	tmp = g_arena->champs;
	while (tmp->index != (int)c)
		tmp = tmp->next;
	bogie->champ = tmp;
	i = 0;
	while (i < REG_NUMBER)
		bogie->regs[i++] = 0;
	return (bogie);
}

void		free_bogie(t_bogie *tmp)
{
	free(tmp->regs);
	free(tmp);
}

t_bogie		*delete_bogie(t_bogie *bogie)
{
	t_bogie	*tmp;
	t_bogie	*prev;
	t_bogie	*next;

	tmp = g_arena->bogie_head;
	prev = tmp;
	if (tmp->next == NULL || tmp->num == bogie->num)
	{
		g_arena->bogie_head = tmp->next;
		next = tmp->next;
		free_bogie(tmp);
		g_arena->all_bogies--;
		return (next);
	}
	while (tmp && tmp->num != bogie->num)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	next = tmp->next;
	prev->next = next;
	free_bogie(tmp);
	g_arena->all_bogies--;
	return (next);
}

size_t		count_bogies(void)
{
	t_bogie	*tmp;
	size_t	c;

	c = 0;
	tmp = g_bogies;
	while (tmp)
	{
		tmp = tmp->next;
		c++;
	}
	return (c);
}
