#include "vm.h"

void	battlefield_print(t_coliseum *field)
{
	size_t i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (field->list[i].bogie == 1)
			ft_printf(" \x1b[46m%{black}02x", field->list[i].com);
		else
		{
			if (field->list[i].color == 'g')
				ft_printf(" %{green}02x", field->list[i].com);
			if (field->list[i].color == 'r')
				ft_printf(" %{red}02x", field->list[i].com);
			if (field->list[i].color == 'y')
				ft_printf(" %{yellow}02x", field->list[i].com);
			if (field->list[i].color == 'b')
				ft_printf(" %{blue}02x", field->list[i].com);
			if (field->list[i].color == 'e')
				ft_printf(" %{grey}02x", field->list[i].com);
				// ft_printf(" %02x", field->list[i].com);
		}
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
			{
				field->list[j + (i * c)].com = warriors->code[j];
				field->list[j + (i * c)].bogie = 0;
				field->list[j + (i * c)].champ = i + 1;
				if (i == 0)
					field->list[j + (i * c)].color = 'g';
				else if (i == 1)
					field->list[j + (i * c)].color = 'r';
				else if (i == 2)
					field->list[j + (i * c)].color = 'y';
				else if (i == 3)
					field->list[j + (i * c)].color = 'b';
			}
			else
			{
				field->list[j + (i * c)].com = 0;
				field->list[j + (i * c)].bogie = 0;
				field->list[j + (i * c)].champ = 0;
				field->list[j + (i * c)].color = 'e';
			}
			j++;
		}
		warriors = warriors->next;
		i++;
	}
	if (MEM_SIZE % num != 0)
	{
		field->list[MEM_SIZE - 1].com = 0;
		field->list[MEM_SIZE - 1].bogie = 0;
		field->list[MEM_SIZE - 1].champ = 0;
		field->list[MEM_SIZE - 1].color = 'e';
	}
	return (field);
}
