#include "vm.h"

void	init_champ(t_champ **champ)
{
	(*champ)->name = NULL;
	(*champ)->code = NULL;
	(*champ)->comment = NULL;
	(*champ)->next = NULL;
}

t_champ		*create_champ(t_champ **head, char *file)
{
	t_champ			*champ;

	champ = NULL;
	if ((*head) == NULL)
	{
		(*head) = (t_champ*)malloc(sizeof(t_champ));
		init_champ(head);
		parse_bytecode(*head, file);
		return (*head);
	}
	else
	{
		champ = (t_champ*)malloc(sizeof(t_champ));
		init_champ(&champ);
		parse_bytecode(champ, file);
	}
	return (champ);
}

void		delete_champs(t_champ *head)
{
	t_champ	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->code);
		free(tmp->name);
		free(tmp->comment);
		free(tmp);
	}
}

void	add_first_champ(t_champ **head, int n, size_t lst_len)
{
	if (n == -1)
		(*head)->index = lst_len;
	else
	{
		(*head)->index = n;
		lst_len;
	}
}

void	insert_to_position(int n, t_champ **head, t_champ *new)
{
	size_t	i;

	i = (*head)->index;
	while (i > n)
	{
		(*head) = (*head)->next;
		i = (*head)->index;
	}
	new->index = n;
	new->next = (*head)->next;
	(*head)->next = new;
}

// void	insert_champ_to_position(t_champ **head, t_champ *new, int n)
// {
// 	t_champ	*tmp;

// 	tmp = (*head);
// 	if (tmp->index == n)
// 	{
// 		new->index = n;
// 	}
// }

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
		{
			new->index = ++lst_len;
			new->next = (*head);
			(*head) = new;
		}
		// else
		// {
		// 	insert_champ_to_position(head, new, n);
		// 	lst_len++;
		// }
	}
}

int		add_champion(char *file, int index, t_champ **champs)
{
	t_champ	*new;

	new = NULL;
	new = create_champ(champs, file);
	add_to_list(champs, new, index);
	if (index != -1)
		index = -1;
	return (index);
}

int			check_num(char *arg, int c)
{
	size_t	i;
	int		n;

	i = 0;
	n = -1;
	if (arg[i] >= '1' && arg[i] <= '9')
	{
		if ((n = ft_atoi(arg)) > c - 3)
		{
			n = -2;
			ft_errno(6);
		}
	}
	else
	{
		ft_errno(6);
		n = -2;
	}
	return (n);
}

t_champ		*parse_args(int c, char **a)
{
	int		i;
	int		n;
	t_champ	*champs;

	champs = NULL;
	i = 1;
	n = -1;
	while (i < c)
	{
		if (ft_rstrcmp(a[i], ".cor") == 1)
			n = add_champion(a[i], n, &champs);
		else if (ft_rstrcmp(a[i], "-n") == 1)
		{
			if ((n = check_num(a[++i], c)) == -2)
			{
				delete_champs(champs);
				return (NULL);
			}
		}
		else
		{
			ft_errno(2);
			return (NULL);
		}
		i++;
	}
	return (champs);
}

int		main(int c, char **a)
{
	t_champ	*champs;
	t_champ *tmp;

	if (c < 2)
		return (ft_errno(0));
	champs = parse_args(c, a);
	tmp = champs;
	while (tmp) {
		ft_printf("%s %d\n", tmp->name, tmp->index);
		tmp = tmp->next;
	}
	delete_champs(champs);
}
