/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_4bytes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:25:15 by kbethany          #+#    #+#             */
/*   Updated: 2019/11/27 12:31:21 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_4bytes(int a1, int a2, int a3, int flag_l)
{
	int	c;

	if (flag_l)
		c = a1 + a2;
	else
		c = (a1 + a2) % IDX_MOD;
	a3 = g_bogies->regs[a3];
	c = (g_bogies->index + c) % MEM_SIZE;
	g_arena->list[c].com = a3 >> 24;
	g_arena->list[c].color = g_bogies->color;
	g_arena->list[c].champ = g_bogies->num * (-1);
	g_arena->list[(1 + c) % MEM_SIZE].com = (a3 << 8) >> 24;
	g_arena->list[(1 + c) % MEM_SIZE].color = g_bogies->color;
	g_arena->list[(1 + c) % MEM_SIZE].champ = g_bogies->num * (-1);
	g_arena->list[(2 + c) % MEM_SIZE].com = (a3 << 16) >> 24;
	g_arena->list[(2 + c) % MEM_SIZE].color = g_bogies->color;
	g_arena->list[(2 + c) % MEM_SIZE].champ = g_bogies->num * (-1);
	g_arena->list[(3 + c) % MEM_SIZE].com = (a3 << 24) >> 24;
	g_arena->list[(3 + c) % MEM_SIZE].color = g_bogies->color;
	g_arena->list[(3 + c) % MEM_SIZE].champ = g_bogies->num * (-1);
}

int		reg_or_dir(int *arg, unsigned char arg_byte, int num)
{
	int	reg;

	if (is_treg(arg_byte, num))
	{
		if ((reg = get_treg(g_bogies->aim)) < 16)
		{
			g_bogies->aim++;
			*arg = g_bogies->regs[reg];
			return (1);
		}
	}
	else if (is_tdir(arg_byte, num))
	{
		*arg = get_tdir_small_size((g_bogies->index + g_bogies->aim)\
					% MEM_SIZE);
		g_bogies->aim += 2;
		return (1);
	}
	return (-1);
}

int		get_small_arg(int *arg, int position, unsigned char arg_byte)
{
	int	reg;

	if (is_treg(arg_byte, position))
	{
		reg = 0;
		if ((reg = get_treg(g_bogies->aim)) < 16)
		{
			*arg = g_bogies->regs[reg];
			g_bogies->aim++;
			return (1);
		}
		else
			return (-1);
	}
	else if (is_tdir(arg_byte, position))
	{
		*arg = get_tdir_small_size((g_bogies->index + g_bogies->aim)\
					% MEM_SIZE);
		g_bogies->aim += 2;
		return (1);
	}
	else if (is_tind(arg_byte, position))
	{
		*arg = get_tind(0, g_bogies->aim);
		g_bogies->aim += 2;
		return (1);
	}
	return (-1);
}
