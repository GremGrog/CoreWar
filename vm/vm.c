#include "vm.h"

int			ft_rstrcmp(const char *str1, const char *str2)
{
	size_t	index;
	size_t  len1;
	size_t  len2;

	index = 0;
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (!str1 || !str2)
		return (0);
	while ((str1[len1 - index] || str2[len2 - index]))
	{
		if (str1[len1 - index] != str2[len2 - index])
		{
			return ((int)((unsigned char)str1[len1 - index] - \
			(unsigned char)str2[len2 - index]));
		}
		index++;
	}
	return (0);
}

void	init_champ(t_champ **champ)
{
	(*champ)->name = NULL;
	(*champ)->code = NULL;
	(*champ)->comment = NULL;
	(*champ)->next = NULL;		
}

void	list_add(t_champ **head, t_champ *new, int i)
{
	static size_t	lst_len = 0;
	
	if (lst_len == 0)
	{	
		if (i == -1)
			(*head)->index = ++lst_len;
		else
		{
			(*head)->index = i;
			lst_len++;
		}
	}
	else
	{
		if (i != -1 && i > lst_len)
		{
			new->index = i;
			new->next = *head;
			*head = new;
		}
		// if (i != -1 && i < lst_len)
		// 	change_indexes(&head, new, i);
		else
		{
			new->index = ++lst_len;
			new->next = (*head);
			(*head) =new;
		}
	}
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

t_champ		*parse_args(int c, char **a)
{
	int		i;
 	int		n;
	t_champ	*champs;
	t_champ	*new;

	i = 1;
	n = -1;
	champs = NULL;
	new = NULL;
  	while (i < c)
  	{
    	if (ft_rstrcmp(a[i],".cor") == 0)
		{
			new = create_champ(&champs, a[i]);
      		list_add(&champs, new, n);
			if (n != -1)
				n = -1;
		}
		else if (ft_rstrcmp(a[i],"-n") == 0)
			n = ft_atoi(a[i]);
    	else
		{
      		ft_errno(2);
			return (NULL);
		}
    	i++;
  	}
	  return (champs);
}

int main(int c, char **a)
{
  
  t_champ	*champs;
  
	if (c < 2)
		return (ft_errno(0));
	if (c > 4)
    	return (ft_errno(5));
	champs = parse_args(c, a);
}
