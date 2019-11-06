#include "vm.h"

void	battlefield(t_champ *warriors, int num)
{
	t_coliseum	*field;
	size_t i;
	size_t j;
	int c;

	i = 0;
	c = MEM_SIZE / num;
	field = (t_coliseum *)malloc(sizeof(t_coliseum));
	field->raund = 0;
	field->mortal_flip = 0;
	field->doomsday_clock = 0;
	while (i < num)
	{
		j = 0;
		while (j < c)
		{
			if (j < warriors->code_size)
				field->list[j + (i * c)].com = warriors->code[j];
			else
				field->list[j + (i * c)].com = 0;
			ft_printf(" %02x", field->list[j + (i * c)].com);
			if ((j + (i * c)) % 64 == 63)
				write(1, "\n", 1);
			j++;
		}
		warriors = warriors->next;
		i++;
	}
}

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