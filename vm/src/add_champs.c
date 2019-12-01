/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_champs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:03:32 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/29 15:02:37 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		insert_dup(t_champ **head, t_champ *new)
{
	t_champ	*tmp;
	t_champ	*prev;

	tmp = (*head);
	prev = NULL;
	new->index = g_flags->n;
	while (tmp && tmp->index != new->index)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (prev)
		prev->next = new;
	else
		(*head) = new;
	new->next = tmp;
	tmp = (*head);
	while (tmp->next)
	{
		if ((tmp->next && tmp->next->index == tmp->index))
			tmp->next->index++;
		tmp = tmp->next;
	}
	return (1);
}

int		add_first_champ(t_champ **head, size_t lst_len)
{
	if (g_flags->n == 0)
		(*head)->index = lst_len;
	else
		(*head)->index = g_flags->n;
	return (0);
}

int		insert_champ(t_champ **head, t_champ *new)
{
	t_champ	*tmp;

	tmp = (*head);
	if (g_flags->n == 0)
		new->index = search_unique_num(head);
	else
	{
		if (search_unique_num(head) != (int)g_flags->n)
			return (insert_dup(head, new));
		else
			new->index = g_flags->n;
	}
	if (new->index < tmp->index)
	{
		new->next = (*head);
		(*head) = new;
		return (1);
	}
	while (tmp->next && tmp->next->index < new->index)
		tmp = tmp->next;
	new->next = tmp->next;
	tmp->next = new;
	return (1);
}

int		add_to_list(t_champ **head, t_champ *new)
{
	static size_t	lst_len = 0;
	t_champ			*tmp;

	tmp = *head;
	if (lst_len + 1 > MAX_PLAYERS)
	{
		ft_fprintf(2, "Too much champions, max numbers of champions %d\n",
		MAX_PLAYERS);
		delete_champ(new);
		delete_champs(*head);
		return (-2);
	}
	if (lst_len == 0)
		return (add_first_champ(head, ++lst_len));
	else
	{
		lst_len++;
		return (insert_champ(head, new));
	}
	return (0);
}

int		add_champion(char *file, t_champ **champs)
{
	t_champ	*new;

	new = NULL;
	if ((new = create_champ(champs, file)) == NULL)
		return (-2);
	if ((add_to_list(champs, new)) == -2)
		return (-2);
	if (g_flags->n > 0)
		g_flags->n = 0;
	return (1);
}
