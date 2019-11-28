/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 13:12:20 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 13:12:54 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		ft_errno(int x)
{
	if (x == 0)
		ft_fprintf(2, "error: no argument\n");
	if (x == 1)
		ft_fprintf(2, "error: wrong number after flag -n\n");
	if (x == 2)
		ft_fprintf(2, "error: wrong argument\n");
	if (x == 3)
		ft_fprintf(2, "error: invalid champion file\n");
	if (x == 4)
		ft_fprintf(2, "error: invalid champion code size\n");
	if (x == 5)
		ft_fprintf(2, "error: too many argument\n");
	if (x == 6)
		ft_fprintf(2, "error: wrong number for champion\n");
	if (x == 7)
		ft_fprintf(2, "error: invalid flag\n");
	return (0);
}
