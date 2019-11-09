#include "vm.h"

void	aff(void)
{
	unsigned char	arg_byte;
    int				arg;
	char			sym;

	arg_byte = g_arena->list[g_bogies->index + 1].com;
    if (IS_T_REG(arg_byte, FIRST_ARG))
    {
        arg = get_treg(g_bogies->index + 2);
		sym = (char)g_bogies->regs[arg];
        ft_printf("%c", (char)arg);
		g_bogies->aim = 3;
		move_caret(g_bogies->aim);
    }
	else
		scip_bytes(AFF_OP);
}