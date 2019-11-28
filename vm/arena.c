/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:59:30 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 12:13:35 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	battlefield_print(void)
{
	size_t	i;
	size_t	r;

	i = 0;
	r = 0;
	ft_printf("0x%04x : ", r);
	while (i < MEM_SIZE)
	{
		ft_printf("%02x ", g_arena->list[i].com);
		if (i % 64 == 63)
		{
			write(1, "\n", 1);
			r += 64;
			if (r < MEM_SIZE)
				ft_printf("0x%04x : ", r);
		}
		i++;
	}
}

void	insert_zeros_to_battlefield(size_t j, size_t i, size_t c)
{
	g_arena->list[j + (i * c)].com = 0;
	g_arena->list[j + (i * c)].bogie = 0;
	g_arena->list[j + (i * c)].champ = 0;
	g_arena->list[j + (i * c)].color = 'e';
}

void	isnert_champ_code_to_battlefield(t_champ *warriors, size_t i, size_t c)
{
	size_t	j;

	j = 0;
	while (j < c)
	{
		if (j < warriors->code_size)
		{
			g_arena->list[j + (i * c)].com = warriors->code[j];
			g_arena->list[j + (i * c)].bogie = 0;
			g_arena->list[j + (i * c)].champ = i + 1;
			if (warriors->index == 1)
				g_arena->list[j + (i * c)].color = 'g';
			else if (warriors->index == 2)
				g_arena->list[j + (i * c)].color = 'r';
			else if (warriors->index == 3)
				g_arena->list[j + (i * c)].color = 'y';
			else if (warriors->index == 4)
				g_arena->list[j + (i * c)].color = 'b';
		}
		else
			insert_zeros_to_battlefield(j, i, c);
		j++;
	}
}

void	insert_code_to_battlefield(size_t num, t_champ *champs)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = MEM_SIZE / num;
	while (i < num)
	{
		isnert_champ_code_to_battlefield(champs, i, c);
		champs = champs->next;
		i++;
	}
}

void	init_battlefield(t_champ *warriors, size_t num)
{
	g_arena = (t_coliseum *)malloc(sizeof(t_coliseum));
	g_arena->champ_num = num;
	g_arena->round = 0;
	g_arena->mortal_flip = 0;
	g_arena->doomsday_clock = 0;
	g_arena->death_gaze = 0;
	g_arena->cycle_to_die = CYCLE_TO_DIE;
	g_arena->champs = warriors;
	g_arena->last_stand = 0;
	g_arena->all_bogies = 0;
	g_arena->max_bogie_num = 0;
	insert_code_to_battlefield(num, warriors);
	if (MEM_SIZE % num != 0)
	{
		g_arena->list[MEM_SIZE - 1].com = 0;
		g_arena->list[MEM_SIZE - 1].bogie = 0;
		g_arena->list[MEM_SIZE - 1].champ = 0;
		g_arena->list[MEM_SIZE - 1].color = 'e';
	}
}
