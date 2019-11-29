/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:23:14 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/29 15:15:15 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_arg(int *arg, int position, unsigned char arg_byte)
{
	int	reg;

	reg = 0;
	if ((is_treg(arg_byte, position))
	&& (reg = get_treg(g_bogies->aim)) < REG_NUMBER)
	{
		g_bogies->aim++;
		*arg = g_bogies->regs[reg];
		return (1);
	}
	else if (is_tdir(arg_byte, position))
	{
		*arg = get_tdir_big_size((g_bogies->index + g_bogies->aim) % MEM_SIZE);
		g_bogies->aim += 4;
		return (1);
	}
	else if (is_tind(arg_byte, position))
	{
		*arg = get_tind(g_bogies->aim);
		g_bogies->aim += 2;
		return (1);
	}
	return (-1);
}

void	bitwise_and(void)
{
	unsigned char	arg_byte;
	int				arg1;
	int				arg2;
	int				reg;

	arg1 = 0;
	arg2 = 0;
	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 2;
	if ((get_arg(&arg1, FIRST_ARG, arg_byte)) == -1
	|| (get_arg(&arg2, SECOND_ARG, arg_byte)) == -1
	|| (!(is_treg(arg_byte, THIRD_ARG)))
	|| (reg = get_treg(g_bogies->aim)) >= REG_NUMBER)
	{
		skip_bytes(AND_OP);
		return ;
	}
	if ((g_bogies->regs[reg] = arg1 & arg2) == 0)
		g_bogies->carry = 1;
	else
		g_bogies->carry = 0;
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | and %d %d r%d\n",\
							g_bogies->num, arg1, arg2, reg + 1);
	move_caret(g_bogies->aim + 1);
}

void	bitwise_or(void)
{
	unsigned char	arg_byte;
	int				arg1;
	int				arg2;
	int				reg;

	arg1 = 0;
	arg2 = 0;
	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 2;
	if ((get_arg(&arg1, FIRST_ARG, arg_byte)) == -1
	|| (get_arg(&arg2, SECOND_ARG, arg_byte)) == -1
	|| (!(is_treg(arg_byte, THIRD_ARG)))
	|| (reg = get_treg(g_bogies->aim)) >= REG_NUMBER)
	{
		skip_bytes(OR_OP);
		return ;
	}
	if ((g_bogies->regs[reg] = arg1 | arg2) == 0)
		g_bogies->carry = 1;
	else
		g_bogies->carry = 0;
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | or %d %d r%d\n", \
						g_bogies->num, arg1, arg2, reg + 1);
	move_caret(g_bogies->aim + 1);
}

void	bitwise_xor(void)
{
	unsigned char	arg_byte;
	int				arg1;
	int				arg2;
	int				reg;

	arg1 = 0;
	arg2 = 0;
	arg_byte = g_arena->list[(g_bogies->index + 1) % MEM_SIZE].com;
	g_bogies->aim = 2;
	if ((get_arg(&arg1, FIRST_ARG, arg_byte)) == -1
	|| (get_arg(&arg2, SECOND_ARG, arg_byte)) == -1
	|| (!(is_treg(arg_byte, THIRD_ARG)))
	|| (reg = get_treg(g_bogies->aim)) >= REG_NUMBER)
	{
		skip_bytes(XOR_OP);
		return ;
	}
	if ((g_bogies->regs[reg] = arg1 ^ arg2) == 0)
		g_bogies->carry = 1;
	else
		g_bogies->carry = 0;
	if (g_flags->v == 1 || g_flags->v == 30)
		ft_printf("P %4d | xor %d %d r%d\n", \
								g_bogies->num, arg1, arg2, reg + 1);
	move_caret(g_bogies->aim + 1);
}
