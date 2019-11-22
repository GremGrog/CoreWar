#include "vm.h"

void	introduce_champs(void)
{
	t_champ	*champs;

	champs = g_arena->champs;
	ft_printf("Introducing contestants...\n");
	while (champs)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", champs->index, champs->code_size, champs->name, champs->comment);
		champs = champs->next;
	}
}

void	introduce_winner(void)
{
	t_champ	*champs;

	champs = g_arena->champs;
	if (g_arena->last_stand != 0)
	{
		while (champs && champs->index * (-1) != g_arena->last_stand)
			champs = champs->next;
	}
	ft_printf("Contestant %d, \"%s\", has won !\n", champs->index, champs->name);
}