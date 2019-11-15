#include "vm.h"

unsigned int		get_tdir_big_size(int i)
{
	unsigned int		tdir;
	size_t	c;

	c = 0;
	tdir = 0;
	while (c < DIR_SIZE)
	{
		tdir |= g_arena->list[i].com;
		if (c <= 2)
			tdir <<= 8;
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
	tdir = 0x0;
	while (c < 2)
	{
		tdir <<= 8;
		tdir += g_arena->list[i].com;
		i++;
		c++;
	}
	return ((short)tdir);
}

int		get_treg(int scip_size)
{
	int		treg;
	size_t	i;

	i = g_bogies->index + scip_size;
	treg = g_arena->list[i].com;
//	if (g_arena->round > 952)
//		printf("treg %d\n", treg);
	return (--treg);
}

unsigned int		get_tind(int size_flag, int scip_size)
{
	short			tind;
	unsigned int	temp;

	tind = get_tdir_small_size(g_bogies->index + scip_size);
	tind %= IDX_MOD;
	if (size_flag == 1)
		temp = get_tdir_big_size(tind);
	else
		temp = get_tdir_small_size(tind);
	return (temp);
}
