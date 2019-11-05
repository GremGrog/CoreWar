#include "vm.h"

void	battlefield(t_champ *warriors, int num)
{
	t_coliseum	*field;
	size_t i;
	size_t j;
	int c;

	i = 0;
	ft_printf("%d\n", warriors->code_size);
	c = MEM_SIZE / num;
	field = (t_coliseum *)malloc(sizeof(t_coliseum));
	field->raund = 0;
	field->mortal_flip = 0;
	field->doomsday_clock = 0;
	while (i < num)
	{
		j = 0;
		//ft_printf("\n %d\n", c * (i+1));
		while (j < c)
		{
			if (j < warriors->code_size)
				field->list[j + (i * c)].com = warriors->code[j];
			else
				field->list[j + (i * c)].com = 0;
			ft_printf("%x", field->list[j + (i * c)].com );
			j++;
		}
		warriors = warriors->next;
		i++;
	}
}