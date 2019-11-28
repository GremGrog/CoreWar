/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:03:32 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 13:03:55 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add_first_champ(t_champ **head, int n, size_t lst_len)
{
	if (n == -1)
		(*head)->index = lst_len;
	else
		(*head)->index = n;
}

void	insert_champ(t_champ **head, t_champ *new, size_t lst_len)
{
	t_champ	*tmp;

	tmp = (*head);
	new->index = lst_len;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	add_to_list(t_champ **head, t_champ *new, int n)
{
	static size_t	lst_len = 0;
	t_champ			*tmp;

	tmp = *head;
	if (lst_len == 0)
		add_first_champ(head, n, ++lst_len);
	else
	{
		if (n == -1)
			insert_champ(head, new, ++lst_len);
	}
}

int		add_champion(char *file, int index, t_champ **champs)
{
	t_champ	*new;

	new = NULL;
	if ((new = create_champ(champs, file)) == NULL)
		return (-2);
	add_to_list(champs, new, index);
	if (index != -1)
		index = -1;
	return (index);
}
