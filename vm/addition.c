/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:43:19 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 11:52:10 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	addition(void)
{
	unsigned char	arg_byte;
	int				reg1;
	int				reg2;
	int				reg3;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	if (is_treg(arg_byte, FIRST_ARG) && is_treg(arg_byte, SECOND_ARG) &&
		is_treg(arg_byte, THIRD_ARG)
		&& ((reg1 = get_treg(2)) < 16)
		&& ((reg2 = get_treg(3)) < 16)
		&& ((reg3 = get_treg(4)) < 16))
	{
		g_bogies->regs[reg3] = g_bogies->regs[reg1] + \
												g_bogies->regs[reg2];
		g_bogies->carry = (g_bogies->regs[reg3] == 0 ? 1 : 0);
		if (g_flags->v == 1 || g_flags->v == 30)
			ft_printf("P %4d | add r%d r%d r%d\n", g_bogies->num, \
										reg1 + 1, reg2 + 1, reg3 + 1);
		move_caret(5);
	}
	else
	{
		skip_bytes(ADD_OP);
		return ;
	}
}
