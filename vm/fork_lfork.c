#include "vm.h"

void	long_fork(void)
{
	unsigned char	arg_byte;
	short			arg;
	t_bogie			*new;

	arg_byte = g_arena->list[g_bogies->index + 1].com;
    if (IS_T_DIR(arg_byte, FIRST_ARG))
    {
		arg = get_tdir_small_size(g_bogies->index + 2);
		new = create_bogie();
		copy_bogie(new, g_bogies);
		g_arena->list[arg].bogie = 1;
		new->index = arg;
		new->next = g_bogies->next;
		g_bogies->next = new;
		move_caret(3);
	}
	// else
		// scip_bytes();
}

void	ft_fork(void)
{
	unsigned char	arg_byte;
	short			arg;
	t_bogie			*new;

	arg_byte = g_arena->list[g_bogies->index + 1].com;
    if (IS_T_DIR(arg_byte, FIRST_ARG))
    {
		arg = get_tdir_small_size(g_bogies->index + 2);
		arg %= IDX_MOD;
		new = create_bogie();
		copy_bogie(new, g_bogies);
		g_arena->list[arg].bogie = 1;
		new->index = arg;
		new->next = g_bogies->next;
		g_bogies->next = new;
		move_caret(3);
	}
	// else
		// scip_bytes();
}