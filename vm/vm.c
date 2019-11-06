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
	arena = init_battlefield(champs, champs_num);
	bogies = add_bogies_on_arena(arena);
	// begin_game(arena, bogies);
	battlefield_print(arena);
	delete_champs(tmp);
	// while (amount_alive_cursors > 0)
	// {
	// 	while (cursors)
	// 	{
	// 		exec_operation(cursors);
	// 		cursors->code;
	// 		cursors->exec_cycles;
	// 		cursors = cursors->next;
	// 	}
	// 	if (currsnt_cycle = CDT) {

	// 	}
	// }
}
