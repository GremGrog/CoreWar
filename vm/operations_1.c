#include "vm.h"

int		get_tdir(int i)
{
	int		tdir;
	size_t	c;

	c = 0;
	while (c < DIR_SIZE)
	{
		tdir <<= 8;
		tdir += g_arena->list[i].com;
		i++;
		c++;
	}
	return (tdir);
}

int		get_treg(void)
{
	int		treg;
	size_t	i;

	i = g_bogies->index + 2 + DIR_SIZE;
	treg = g_arena->list[i].com;
	return (treg);
}

int		get_tind(void)
{
	int	tind;

	tind = get_tdir(g_bogies->index + 2);
	tind %= IDX_MOD;
	tind = get_tdir(tind);
	return (tind);
}

void	load(void)
{
	int				arg;
	int				treg;
	unsigned char	arg_byte;

	arg_byte = g_arena->list[g_bogies->index + 1].com;
	arg = 0;
	treg = 0;
	if (IS_T_DIR(arg_byte, FIRST_ARG))
	{
		arg = get_tdir(g_bogies->index + 2);
		treg = get_treg();
	}
	else if (IS_T_IND(arg_byte, FIRST_ARG))
	{
		arg = get_tind();
		treg = get_treg();
	}
	g_bogies->regs[treg] = arg;
	if (arg == 0)
		g_bogies->carry = 1;
	else
		g_bogies->carry = 0;
	g_arena->list[g_bogies->index].bogie = 0;
	g_bogies->index = g_bogies->index + DIR_SIZE + 3;
	g_arena->list[g_bogies->index].bogie = 1;
	g_bogies->commmand = g_arena->list[g_bogies->index].com;
	define_cycles_to_exec(g_bogies->commmand);
}