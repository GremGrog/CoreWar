/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_is_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:07:45 by kbethany          #+#    #+#             */
/*   Updated: 2019/11/26 16:07:52 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		is_treg(unsigned char arg_byte, int position)
{
	if (position == 1)
	{
		if ((arg_byte & 0xc0) == 0x40)
			return (1);
	}
	if (position == 2)
	{
		if ((arg_byte & 0x30) == 0x10)
			return (1);
	}
	if (position == 3)
	{
		if ((arg_byte & 0xC) == 0x4)
			return (1);
	}
	return (0);
}

int		is_tdir(unsigned char arg_byte, int position)
{
	if (position == 1)
	{
		if ((arg_byte & 0xc0) == 0x80)
			return (1);
	}
	if (position == 2)
	{
		if ((arg_byte & 0x30) == 0x20)
			return (1);
	}
	if (position == 3)
	{
		if ((arg_byte & 0xC) == 0x8)
			return (1);
	}
	return (0);
}

int		is_tind(unsigned char arg_byte, int position)
{
	if (position == 1)
	{
		if ((arg_byte & 0xC0) == 0xC0)
			return (1);
	}
	if (position == 2)
	{
		if ((arg_byte & 0x30) == 0x30)
			return (1);
	}
	if (position == 3)
	{
		if ((arg_byte & 0xC) == 0xC)
			return (1);
	}
	return (0);
}
