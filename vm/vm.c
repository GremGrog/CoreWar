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

void	add_to_list(t_champ **head, t_champ *new, int n)
{
	static size_t	lst_len = 0;

	if (lst_len == 0)
		add_first_champ(head, n, ++lst_len);
	else
	{
		if (n != -1 && n > (int)lst_len)
		{
			new->index = n;
			new->next = *head;
			*head = new;
		}
		// if (n != -1 && n < (int)lst_len)
		// 	change_indexes(&head, new, n);
		else
		{
			new->index = ++lst_len;
			new->next = (*head);
			(*head) = new;
		}
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
	if (arg[i] >= '0' && arg[i] <= '9')
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
		if (ft_rstrcmp(a[i], ".cor") == 0)
			n = add_champion(a[i], n, &champs);
		else if (ft_rstrcmp(a[i], "-n") == 0)
		{
			if ((n = check_num(a[++i], c)) == -2)
				return (delete_champs(&champs));
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

	if (c < 2)
		return (ft_errno(0));
	champs = parse_args(c, a);
	while (champs) {
		ft_printf("%s\n", champs->name);
		champs = champs->next;
	}
}
