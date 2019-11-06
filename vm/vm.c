#include "vm.h"

int		main(int c, char **a)
{
	t_champ		*champs;
	t_coliseum	*arena;
	int			champs_num;

	if (c < 2)
		return (ft_errno(0));
	champs = parse_args(c, a);
	champs_num = count_champs(champs);
	arena = init_battlefield(champs, champs_num);
	battlefield_print(arena);
	add_bogies_on_arena(arena);
	delete_champs(champs);
}
