#include "vm.h"

void	move_caret(int steps)
{
	int i;

	i = 0;
	if ((g_flags->v == 5 || g_flags->v == 30) && steps != 1 && 
		(!(g_bogies->commmand == g_op[8].code && g_bogies->carry == 1)))
	{
		ft_printf("ADV %d (0x%04x -> 0x%04x) ", steps, g_bogies->index, g_bogies->index + steps);
		while (i < steps)
		{
			ft_printf("%02x ", g_arena->list[(g_bogies->index + i) % MEM_SIZE].com);
			i++;
		}
		ft_printf("\n");
	}
	g_arena->list[g_bogies->index].bogie = 0;
	g_bogies->index = (g_bogies->index + steps) % MEM_SIZE;
	g_arena->list[g_bogies->index].bogie = 1;
	g_bogies->its_a_highnoon = 0;
	g_bogies->aim = 0;
}

void	count_first_args_len(int op_code, unsigned char arg_byte, int position)
{
	if (is_tdir(arg_byte, position))
	{
		if (g_op[op_code].t_dir_size == 4)
			g_bogies->aim += DIR_SIZE;
		else
			g_bogies->aim += 2;
	}
	if (is_treg(arg_byte, position))
		g_bogies->aim += 1;
	if (is_tind(arg_byte, position))
		g_bogies->aim += 2;
}

void	skip_bytes(int op_code)
{
	unsigned char	arg_byte;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 1;
	count_first_args_len(op_code, arg_byte, FIRST_ARG);
	if (g_op[op_code].args_num > 1)
		count_first_args_len(op_code, arg_byte, SECOND_ARG);
	if (g_op[op_code].args_num == 3)
		count_first_args_len(op_code, arg_byte, THIRD_ARG);
	move_caret(g_bogies->aim + 1);
}
