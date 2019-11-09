#include "vm.h"

int		get_tdir_big_size(int i)
{
	int		tdir;
	size_t	c;

	c = 0;
	tdir = 0;
	while (c < DIR_SIZE)
	{
		tdir <<= 8;
		tdir += g_arena->list[i].com;
		i++;
		c++;
	}
	return (tdir);
}

short		get_tdir_small_size(int i)
{
	int		tdir;
	size_t	c;

	c = 0;
	tdir = 0;
	while (c < 2)
	{
		tdir <<= 8;
		tdir += g_arena->list[i].com;
		i++;
		c++;
	}
	return (tdir);
}

int		get_treg(int scip_size)
{
	int		treg;
	size_t	i;

	i = g_bogies->index + scip_size;
	treg = g_arena->list[i].com;
	return (treg);
}

int		get_tind(int size_flag, int scip_size)
{
	int	tind;

	if (size_flag == 1)
		tind = get_tdir_big_size(g_bogies->index + scip_size);
	else
		tind = get_tdir_small_size(g_bogies->index + scip_size);
	tind %= IDX_MOD;
	if (size_flag == 1)
		tind = get_tdir_big_size(tind);
	else
		tind = get_tdir_small_size(tind);
	return (tind);
}