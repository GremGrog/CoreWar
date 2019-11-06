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

t_coliseum	*battlefield(t_champ *warriors, int num)
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
	return (battlefield);
}
