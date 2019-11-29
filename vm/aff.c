/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:54:50 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/29 15:11:51 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	aff(void)
{
	unsigned char	arg_byte;
	int				reg;
	char			sym;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	if (is_treg(arg_byte, FIRST_ARG) && (reg = get_treg(2)) < REG_NUMBER)
	{
		sym = g_bogies->regs[reg];
		if (g_flags->a != 0 || g_flags->v == 30)
			ft_printf("Aff: %c\n", sym);
		g_bogies->aim = 3;
		move_caret(g_bogies->aim);
	}
	else
	{
		skip_bytes(AFF_OP);
		return ;
	}
}
