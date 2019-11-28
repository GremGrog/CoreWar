/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:08:32 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 13:10:59 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_champ(t_champ **champ)
{
	(*champ)->name = NULL;
	(*champ)->code = NULL;
	(*champ)->comment = NULL;
	(*champ)->next = NULL;
	(*champ)->index = 0;
}

t_champ		*create_head(t_champ **head, char *file)
{
	(*head) = (t_champ*)malloc(sizeof(t_champ));
	init_champ(head);
	if ((parse_bytecode(*head, file)) == -2)
	{
		delete_champ(*head);
		return (NULL);
	}
	return (*head);
}

t_champ		*create_champ(t_champ **head, char *file)
{
	t_champ			*champ;

	champ = NULL;
	if ((*head) == NULL)
		return (create_head(head, file));
	else
	{
		champ = (t_champ*)malloc(sizeof(t_champ));
		init_champ(&champ);
		if ((parse_bytecode(champ, file)) == -2)
		{
			delete_champ(champ);
			delete_champs(*head);
			return (NULL);
		}
	}
	return (champ);
}
