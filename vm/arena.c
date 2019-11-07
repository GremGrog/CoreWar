#include "vm.h"

void	battlefield_print(void)
{
	size_t i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (g_arena->list[i].bogie == 1)
			ft_printf(" \x1b[46m%{black}02x", g_arena->list[i].com);
		else
		{
			if (g_arena->list[i].color == 'g')
				ft_printf(" %{green}02x", g_arena->list[i].com);
			if (g_arena->list[i].color == 'r')
				ft_printf(" %{red}02x", g_arena->list[i].com);
			if (g_arena->list[i].color == 'y')
				ft_printf(" %{yellow}02x", g_arena->list[i].com);
			if (g_arena->list[i].color == 'b')
				ft_printf(" %{blue}02x", g_arena->list[i].com);
			if (g_arena->list[i].color == 'e')
				ft_printf(" %{grey}02x", g_arena->list[i].com);
				// ft_printf(" %02x", field->list[i].com);
		}
		if (i % 64 == 63)
			write(1, "\n", 1);
		i++;
	}
}

void	init_battlefield(t_champ *warriors, int num)
{
	size_t i;
	size_t j;
	int c;

	i = 0;
	g_arena = (t_coliseum *)malloc(sizeof(t_coliseum));
	g_arena->champ_num = num;
	g_arena->round = 0;
	g_arena->mortal_flip = 0;
	g_arena->doomsday_clock = 0;
	c = MEM_SIZE / num;
	while (i < num)
	{
		j = 0;
		while (j < c)
		{
			if (j < warriors->code_size)
			{
				g_arena->list[j + (i * c)].com = warriors->code[j];
				g_arena->list[j + (i * c)].bogie = 0;
				g_arena->list[j + (i * c)].champ = i + 1;
				if (i == 0)
					g_arena->list[j + (i * c)].color = 'g';
				else if (i == 1)
					g_arena->list[j + (i * c)].color = 'r';
				else if (i == 2)
					g_arena->list[j + (i * c)].color = 'y';
				else if (i == 3)
					g_arena->list[j + (i * c)].color = 'b';
			}
			else
			{
				g_arena->list[j + (i * c)].com = 0;
				g_arena->list[j + (i * c)].bogie = 0;
				g_arena->list[j + (i * c)].champ = 0;
				g_arena->list[j + (i * c)].color = 'e';
			}
			j++;
		}
		warriors = warriors->next;
		i++;
	}
	if (MEM_SIZE % num != 0)
	{
		g_arena->list[MEM_SIZE - 1].com = 0;
		g_arena->list[MEM_SIZE - 1].bogie = 0;
		g_arena->list[MEM_SIZE - 1].champ = 0;
		g_arena->list[MEM_SIZE - 1].color = 'e';
	}
}
