#include "vm.h"

void	aff(void)
{
	unsigned char	arg_byte;
    int				reg;
	char			sym;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
    if (is_treg(arg_byte, FIRST_ARG))
    {
        reg = g_arena->list[(g_bogies->index + 2) % MEM_SIZE].com;
		reg--;
		if (reg >= 16)
		{
			skip_bytes(AFF_OP);
			return ;
		}
		sym = g_bogies->regs[reg];
		if (g_flags->a != 0 || g_flags->v == 30)
        	ft_printf("Aff: %c\n", sym);
		g_bogies->aim = 3;
		move_caret(g_bogies->aim);
    }
	else
	{
		skip_bytes(AFF_OP);
		return ;
	}
}
