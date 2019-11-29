/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:12:20 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/29 17:09:43 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	usage_print(void)
{
	ft_printf(2, "usage: ./corewar [-i] [-dump N] [-n N] [-a] [-v N]
	example.cor ...\n-i				: visualisator\n
	-dump N		: Dumps memory after N cycles then exits\n
	-n N			: set the champion number\n
	-a				: Print output from \"aff\"\n
	-v N			: verbose\n
						- 1		:	Show opearions information\n
						- 2		: Show cycles information\n
						- 3		: Show lives information\n
						- 4		: Show deaths information\n
						- 5		: Show PC movement information\n
						- 30	: Show all information\n");
}

int		ft_errno(int x)
{
	if (x == 0)
		usage_print();
	if (x == 1)
		ft_fprintf(2, "error: wrong number after flag -n\n");
	if (x == 2)
		ft_fprintf(2, "error: wrong argument\n");
	if (x == 3)
		ft_fprintf(2, "error: invalid champion file\n");
	if (x == 4)
		ft_fprintf(2, "error: invalid champion code size\n");
	if (x == 5)
		ft_fprintf(2, "error: too many arguments\n");
	if (x == 6)
		ft_fprintf(2, "error: wrong number for champion\n");
	if (x == 7)
		ft_fprintf(2, "error: invalid flag\n");
	return (0);
}
