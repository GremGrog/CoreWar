#include "vm.h"

void	battlefield(t_champ *warriors, int num)
{
	t_coliseum	*field;
	int i;
	int j;
	int c;

	i = 0;
	c = MEM_SIZE / num;
	field = (t_coliseum *)malloc(sizeof(t_coliseum));
	field->list = (t_com *)malloc(short * MEM_SIZE);
	field = ft_bzero(field, sizeof(t_coliseum));
	while (warriors[i])
	{
		j = 0;
		while (j < (c * i + 1))
		{
			if (warriors[i]->code[j])
				field->list[j + (i * c)] = warriors[i].code[j];
			else
				field->list[j + (i * c)] = 0;
			j++;
		}
		i++;
	}
}