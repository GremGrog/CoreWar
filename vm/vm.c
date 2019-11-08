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
	tmp = champs;
	champs_num = count_champs(champs);
	init_battlefield(champs, champs_num);
	add_bogies_on_arena();
	fight();
	battlefield_print();
	delete_champs(tmp);
}
