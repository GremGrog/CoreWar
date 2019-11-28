/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:59:48 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 15:00:22 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_flags_struct(void)
{
	g_flags = (t_flags*)malloc(sizeof(t_flags));
	g_flags->dump = 0;
	g_flags->n = 0;
	g_flags->i = 0;
	g_flags->v = 0;
	g_flags->a = 0;
}
