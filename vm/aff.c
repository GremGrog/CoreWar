#include "vm.h"

void	aff(void)
{
	unsigned char	arg_byte;
    int				reg;
	char			sym;

	arg_byte = g_arena->list[g_bogies->index + 1].com;
    if (IS_T_REG(arg_byte, FIRST_ARG))
    {
        reg = get_treg(g_bogies->index + 2);
		if (reg >= 16)
		{
			skip_bytes(arg_byte);
			return ;
		}
		sym = (char)g_bogies->regs[reg];
        ft_printf("%c", (char)reg);
		g_bogies->aim = 3;
		move_caret(g_bogies->aim);
    }
	else
	{
		skip_bytes(arg_byte);
		return ;
	}
}