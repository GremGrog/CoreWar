#include "vm.h"

t_bogie		*create_bogie(void)
{
	t_bogie	*bogie;
	size_t	i;

	bogie = (t_bogie*)malloc(sizeof(t_bogie));
	bogie->num = -1;
	bogie->carry = 0;
	bogie->commmand = 0;
	bogie->last_breath = 0;
	bogie->its_a_highnoon = 0;
	bogie->index = 0;
	bogie->aim = 0;
	bogie->regs = (int*)malloc(sizeof(int) * REG_NUMBER);
	i = 0;
	while (i < REG_NUMBER)
	{
		bogie->regs = 0;
		i++;
	}
	return (bogie);
}

void	delete_bogie(t_bogie *bogie)
{
	free(bogie->regs);
	free(bogie);
}