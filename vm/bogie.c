#include "vm.h"

t_bogie		*create_bogie(void)
{
	t_bogie	*bogie;
	size_t	i;

	bogie = (t_bogie*)malloc(sizeof(t_bogie));
	bogie->num = -1;
	bogie->carry = 0;
	bogie->commmand = 0;
	bogie->last_breath = 0;
	bogie->its_a_highnoon = 0;
	bogie->index = 0;
	bogie->aim = 0;
	bogie->regs = (int*)malloc(sizeof(int) * REG_NUMBER);
	bogie->next = NULL;
	i = 0;
	while (i < REG_NUMBER)
		bogie->regs[i++] = 0;
	return (bogie);
}

void	delete_bogie(t_bogie *bogie)
{
	free(bogie->regs);
	free(bogie);
}

t_bogie	*add_bogies_on_arena(t_coliseum *arena)
{
	size_t	index;
	t_bogie	*head;
	t_bogie	*new;
	size_t	c;
	size_t	step;

	c = 1;
	index = 0;
	head = NULL;
	step = MEM_SIZE / arena->champ_num;
	while (c <= arena->champ_num)
	{
		new = create_bogie();
		new->num = c;
		new->commmand = arena->list[index].com;
		new->its_a_highnoon = define_cycles_to_die(arena->list[index].com);
		new->last_breath = 0;
		new->regs[0] = c * (-1);
		if (head == NULL)
			head = new;
		else if (head != NULL)
		{
			new->next = head;
			head = new;
		}
		arena->list[index].bogie = 1;
		index += step; 
		c++;
	}
	return (head);
}
