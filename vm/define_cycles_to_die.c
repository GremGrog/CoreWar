#include "vm.h"

int		define_cycles_to_die(unsigned char com)
{
	if (com == 0x1 || com == 0x2 || com == 0x3)
		return (5);
	if (com == 0x4 || com == 0x5 || com == 0xd)
		return (10);
	if (com == 0x6 || com == 0x7 || com == 0x8)
		return (6);
	if (com == 0x9)
		return (20);
	if (com == 0xa || com == 0xb)
		return (25);
	if (com == 0xc)
		return (800);
	if (com == 0xe)
		return (50);
	if (com == 15)
		return (1000);
	if (com == 0x10)
		return (2);
	else
		return (-1);
}
