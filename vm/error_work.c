#include "vm.h"

int ft_errno(int x)
{
	if (x == 0)
    	ft_printf("error: no argument\n");
	if (x == 1)
		ft_printf("error: wrong number after flag -n\n");
	if (x == 2)
		ft_printf("error: wrong argument\n");
	if (x == 3)
		ft_printf("error: invalid champion file\n");
	if (x == 4)
		ft_printf("error: invalid champion code size\n");
	if (x == 5)
		ft_printf("error: too many argument\n");
	if (x == 6)
		ft_printf("error: wrong number of champion\n");
  	return (0);
}
