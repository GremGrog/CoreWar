#include "vm.h"

void		copy_bogie(t_bogie *new, t_bogie *bogie)
{
	size_t	i;

	i = 0;
	new->num = bogie->num + 1;
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
	while (tmp->index != c)
		tmp = tmp->next;
	bogie->champ = tmp;
	i = 0;
	while (i < REG_NUMBER)
		bogie->regs[i++] = 0;
	return (bogie);
}

t_bogie		*delete_bogie(t_bogie *bogie)
{
	t_bogie *tmp;
	t_bogie	*prev;
	t_bogie *next;

	tmp = g_arena->bogie_head;
	if (tmp->next == NULL)
	{
		free(tmp->regs);
		free(tmp);
		return (NULL);
	}
	while (tmp->next && tmp->num != bogie->num)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp->next != NULL)
		next = tmp->next;
	else
		next = NULL;
	prev->next = tmp->next;
	free(tmp->regs);
	free(tmp);
	return (prev->next);
}

void	add_bogies_on_arena(void)
{
	size_t	index;
	t_bogie	*new;
	size_t	c;
	size_t	step;

	c = 1;
	index = 0;
	g_bogies = NULL;
	step = MEM_SIZE / g_arena->champ_num;
	while (c <= g_arena->champ_num)
	{
		new = create_bogie(c);
		new->num = c;
		new->index = index;
		new->last_breath = 0;
		new->regs[0] = c * (-1);
		if (g_bogies == NULL)
			g_bogies = new;
		else if (g_bogies != NULL)
		{
			new->next = g_bogies;
			g_bogies = new;
		}
		g_arena->list[index].bogie = 1;
		index += step; 
		c++;
	}
}
