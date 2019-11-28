/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ldi_sti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:42:48 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 13:43:01 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_ldi(int arg_1, int arg_2, int arg_3)
{
	ft_printf("P %4d | ldi %d %d r%d\n       |", g_bogies->num, \
		arg_1, arg_2, arg_3 + 1);
	ft_printf(" -> load from %d + %d = %d (with pc and mod %d)\n",
	arg_1, arg_2, arg_1 + arg_2, \
	g_bogies->index + ((arg_1 + arg_2) % IDX_MOD));
}

void	print_sti(int arg_1, int arg_2, int arg_3)
{
	ft_printf("P %4d | sti r%d %d %d\n       |", \
		g_bogies->num, arg_1 + 1, arg_2, arg_3);
	ft_printf(" -> store to %d + %d = %d (with pc and mod %d)\n", arg_2, \
		arg_3, arg_2 + arg_3, g_bogies->index + ((arg_2 + arg_3) % IDX_MOD));
}

void	print_lldi(int arg_1, int arg_2, int arg_3)
{
	ft_printf("P %4d | lldi %d %d r%d\n       |", g_bogies->num, \
		arg_1, arg_2, arg_3 + 1);
	ft_printf(" -> load from %d + %d = %d (with pc %d)\n", arg_1, arg_2, \
						arg_1 + arg_2, g_bogies->index + (arg_1 + arg_2));
}
