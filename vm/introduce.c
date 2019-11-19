#include "vm.h"

void	introduce_champs(void)
{
	t_champ	*champs;

	champs = g_arena->champs;
	ft_printf("Introducing contestants...\n");
	while (champs)
	{
		ft_printf("* Player %d, weighting %d, \"%s\", (\"%s\") !\n", champs->index, champs->code_size, champs->name, champs->comment);
		champs = champs->next;
	}
}

void	introduce_winner(void)
{
	t_champ	*champs;

	champs = g_arena->champs;
	while (champs->index * (-1) != g_arena->last_stand)
		champs = champs->next;
	ft_printf("Contestant %d \"%s\", has won !\n", champs->index, champs->name);
}