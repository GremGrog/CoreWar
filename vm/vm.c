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
	champs = parse_args(c, a);
	ft_printf("%d\n", g_flags->v);
	tmp = champs;
	champs_num = count_champs(tmp);
	init_battlefield(champs, champs_num);
	add_bogies_on_arena();
	// fight();
	delete_champs(champs);
}
