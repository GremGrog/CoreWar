#include "vm.h"

int		main(int c, char **a)
{
	t_champ		*champs;
	t_champ		*tmp;
	t_bogie		*bogies;
	t_coliseum	*arena;
	int			champs_num;

	if (c < 2)
		return (ft_errno(0));
	champs = NULL;
	champs = parse_args(c, a);
	if (champs != NULL)
	{
		tmp = champs;
		champs_num = count_champs(tmp);
		init_battlefield(champs, champs_num);
		add_bogies_on_arena();
		introduce_champs();
		fight();
		if (g_flags->dump == 0 || g_arena->round < g_flags->dump)
			introduce_winner();
		delete_arena();
		delete_champs(champs);
	}
	free(g_flags);
	if (champs == NULL)
		return (-1);
	return (0);
}
