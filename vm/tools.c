#include "vm.h"

size_t			scip_null_border(size_t i)
{
	size_t	c;

	c = 0;
	while (c++ < NULL_B)
		i++;
	return (i);
}
