/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:08:19 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 13:11:30 by fmasha-h         ###   ########.fr       */
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
