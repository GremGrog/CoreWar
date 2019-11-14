#include "vm.h"

int		search_live_in_bogie(int champ_index)
{
	t_bogie	*tmp_bogie;
	int		live_op;

	tmp_bogie = g_arena->bogie_head;
	live_op = 0;
	while (tmp_bogie)
	{
		if (tmp_bogie->player == champ_index)
			live_op += tmp_bogie->live_op;
		tmp_bogie = tmp_bogie->next;
	}
	return (live_op);
}

int		search_last_breath(int champ_index)
{
	t_bogie	*tmp_bogie;

	tmp_bogie = g_arena->bogie_head;
	while (tmp_bogie)
	{
		if (tmp_bogie->player == champ_index)
			return (tmp_bogie->last_breath);
		tmp_bogie = tmp_bogie->next;
	}
	return (0);
}