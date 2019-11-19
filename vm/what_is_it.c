#include "vm.h"


int		is_treg(unsigned char arg_byte, int position)
{
	if (position == 1)
	{
		if ((arg_byte & 0x40) == 0x40)
			return (1);
	}
	if (position == 2)
	{
		if ((arg_byte^= arg_byte & 0x20) == 0x20)
			return (1);
	}
	if (position == 3)
	{
		if ((arg_byte & 0x4) == 0x4)
			return (1);
	}
	return (0);
}

int		is_tdir(unsigned char arg_byte, int position)
{
	if (position == 1)
	{
		if ((arg_byte & 0x80) == 0x80)
			return (1);
	}
	if (position == 2)
	{
		if ((arg_byte & 0x20) == 0x20)
			return (1);
	}
	if (position == 3)
	{
		if ((arg_byte & 0x8) == 0x8)
			return (1);
	}
	return (0);
}

int		is_tind(unsigned char arg_byte, int position)
{
	if (position == 1)
	{
		if ((arg_byte & 0xC0) == 0xC0)
			return (1);
	}
	if (position == 2)
	{
		if ((arg_byte & 0x30) == 0x30)
			return (1);
	}
	if (position == 3)
	{
		if ((arg_byte & 0xC) == 0xC)
			return (1);
	}
	return (0);
}
