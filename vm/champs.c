#include "vm.h"

void	init_champ(t_champ **champ)
{
	(*champ)->name = NULL;
	(*champ)->code = NULL;
	(*champ)->comment = NULL;
	(*champ)->next = NULL;
	(*champ)->index = 0;
}

t_champ		*create_champ(t_champ **head, char *file)
{
	t_champ			*champ;

	champ = NULL;
	if ((*head) == NULL)
	{
		(*head) = (t_champ*)malloc(sizeof(t_champ));
		init_champ(head);
		if ((parse_bytecode(*head, file)) == -1)
		{
			ft_errno(3);
			free(*head);
			return (NULL);
		}
		return (*head);
	}
	else
	{
		champ = (t_champ*)malloc(sizeof(t_champ));
		init_champ(&champ);
		if ((parse_bytecode(*head, file)) == -2)
		{
			ft_errno(3);
			free(champ);
			delete_champs(*head);
			return (NULL);
		}
	}
	return (champ);
}

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

int		count_champs(t_champ *champs)
{
	t_champ	*tmp;
	size_t	n;

	tmp = champs;
	n = 0;
	while(tmp)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}