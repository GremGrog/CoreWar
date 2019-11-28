/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi_sti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:20:05 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 13:42:57 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ldi(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;
	int				res;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 2;
	res = 0;
	if ((get_small_arg(&arg_1, FIRST_ARG, arg_byte)) == -1
	|| (reg_or_dir(&arg_2, arg_byte, SECOND_ARG) == -1)
	|| ((!(is_treg(arg_byte, THIRD_ARG)))
	|| (arg_3 = get_treg(g_bogies->aim)) >= 16))
	{
		skip_bytes(LDI_OP);
		return ;
	}
	if (g_flags->v == 1 || g_flags->v == 30)
		print_ldi(arg_1, arg_2, arg_3);
	res = (arg_1 + arg_2) % IDX_MOD;
	res = get_tdir_big_size((g_bogies->index + res) % MEM_SIZE);
	g_bogies->regs[arg_3] = res;
	move_caret(g_bogies->aim + 1);
}

void	lldi(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;
	int				res;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 2;
	res = 0;
	if ((get_small_arg(&arg_1, FIRST_ARG, arg_byte)) == -1
	|| (reg_or_dir(&arg_2, arg_byte, SECOND_ARG) == -1)
	|| ((!(is_treg(arg_byte, THIRD_ARG)))
	|| (arg_3 = get_treg(g_bogies->aim)) >= 16))
	{
		skip_bytes(LLDI_OP);
		return ;
	}
	if (g_flags->v == 1 || g_flags->v == 30)
		print_lldi(arg_1, arg_2, arg_3);
	res = (arg_1 + arg_2);
	g_bogies->regs[arg_3] = \
		get_tdir_big_size((g_bogies->index + res) % MEM_SIZE);
	g_bogies->carry = ((g_bogies->regs[arg_3] == 0) ? 1 : 0);
	move_caret(g_bogies->aim + 1);
}

void	sti(void)
{
	int				arg_1;
	int				arg_2;
	int				arg_3;
	unsigned char	arg_byte;

	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 2;
	if ((!(is_treg(arg_byte, FIRST_ARG)))
	|| (arg_1 = get_treg(g_bogies->aim++)) >= 16
	|| ((get_small_arg(&arg_2, SECOND_ARG, arg_byte)) == -1
	|| (reg_or_dir(&arg_3, arg_byte, THIRD_ARG) == -1)))
	{
		skip_bytes(STI_OP);
		return ;
	}
	if (g_flags->v == 1 || g_flags->v == 30)
		print_sti(arg_1, arg_2, arg_3);
	print_4bytes(arg_2, arg_3, arg_1, 0);
	move_caret(g_bogies->aim);
}
