#include "vm.h"

void	battlefield_print(t_coliseum *field)
{
	size_t i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf(" %02x", field->list[i].com);
		if (i % 64 == 63)
			write(1, "\n", 1);
		i++;
	}
}

t_coliseum	*init_battlefield(t_champ *warriors, int num)
{
	t_coliseum	*field;
	size_t i;
	size_t j;
	int c;

	i = 0;
	field = (t_coliseum *)malloc(sizeof(t_coliseum));
	field->champ_num = num;
	field->round = 0;
	field->mortal_flip = 0;
	field->doomsday_clock = 0;
	c = MEM_SIZE / num;
	while (i < num)
	{
		j = 0;
		while (j < c)
		{
			if (j < warriors->code_size)
				field->list[j + (i * c)].com = warriors->code[j];
			else
				field->list[j + (i * c)].com = 0;
			j++;
		}
		warriors = warriors->next;
		i++;
	}
	if (MEM_SIZE % num != 0)
		field->list[j + (i * c)].com = 0;
	return (field);
}

int		define_cycles_to_die(unsigned char com)
{
	if (com == 0x1 || com == 0x2 || com == 0x3)
		return (5);
	if (com == 0x4 || com == 0x5 || com == 0xd)
		return (10);
	if (com == 0x6 || com == 0x7 || com == 0x8)
		return (6);
	if (com == 0x9)
		return (20);
	if (com == 0xa || com == 0xb)
		return (25);
	if (com == 0xc)
		return (800);
	if (com == 0xe)
		return (50);
	if (com == 15)
		return (1000);
	if (com == 0x10)
		return (2);
	else
		return (-1);
}

void	add_bogies_on_arena(t_coliseum *arena)
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
		index += step; 
		c++;
	}
	arena->jumper = head;
		t_bogie	*tmp;
	tmp = arena->jumper;
	while (tmp) {
		ft_printf("%x %d\n", tmp->commmand, tmp->index);
		tmp = tmp->next;
	}
	// return (arena);
}
