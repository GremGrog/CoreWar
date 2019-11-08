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

int		get_tdir_small_size(int i)
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

	tind = get_tdir_big_size(g_bogies->index + 2);
	tind %= IDX_MOD;
	tind = get_tdir_big_size(tind);
	return (tind);
}