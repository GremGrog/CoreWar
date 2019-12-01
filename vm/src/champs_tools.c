/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:08:19 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/29 15:15:33 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		delete_champ(t_champ *tmp)
{
	free(tmp->code);
	free(tmp->name);
	free(tmp->comment);
	free(tmp);
}

void		delete_champs(t_champ *head)
{
	t_champ	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		delete_champ(tmp);
	}
}

int			count_champs(t_champ *champs)
{
	t_champ	*tmp;
	size_t	n;

	tmp = champs;
	n = 0;
	while (tmp)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}

int			search_unique_num(t_champ **head)
{
	t_champ	*tmp;
	int		index;

	tmp = *head;
	index = 1;
	while (tmp)
	{
		if (index == tmp->index)
			index += 1;
		tmp = tmp->next;
	}
	return (index);
}

t_champ		*check_indexes(t_champ *champs)
{
	t_champ	*tmp;

	tmp = champs;
	while (tmp)
	{
		if (tmp->index > MAX_PLAYERS)
		{
			ft_fprintf(2, "Error: invalid number for champion\n");
			delete_champs(champs);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (champs);
}
