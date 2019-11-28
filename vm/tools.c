/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:10:46 by kbethany          #+#    #+#             */
/*   Updated: 2019/11/28 13:00:43 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

size_t		scip_null_border(size_t i)
{
	size_t	c;

	c = 0;
	while (c++ < NULL_B)
		i++;
	return (i);
}

int			ft_rstrcmp(const char *str, const char *substr)
{
	size_t	strlen;
	size_t	sublen;

	if (!str || !substr)
		return (-1);
	strlen = ft_strlen(str) - 1;
	sublen = ft_strlen(substr) - 1;
	if (str[strlen] == substr[sublen] && strlen == 0 && sublen == 0)
		return (1);
	while (strlen > 0 && sublen > 0)
	{
		if (str[strlen] == substr[sublen])
		{
			strlen--;
			sublen--;
		}
		if (str[strlen] != substr[sublen] && sublen == 0)
			return (1);
		if (str[strlen] != substr[sublen] && sublen != 0)
			return (0);
	}
	return (1);
}

int			check_file_size(size_t i, char *file, unsigned char *buf)
{
	if (i > FILE_SIZE)
	{
		i -= FILE_SIZE;
		ft_fprintf(2, "Error: File %s has too large a code \
		(%d bytes > %d bytes)\n", file, i + CHAMP_MAX_SIZE, CHAMP_MAX_SIZE);
		free(buf);
		return (-1);
	}
	return (0);
}

int			check_magic_header(unsigned char *bytecode, t_champ *champ)
{
	int				magic;
	size_t			i;

	magic = 0x0;
	i = 0;
	while (i < MAGIC_NUM_B)
	{
		magic <<= 8;
		magic |= bytecode[i];
		i++;
	}
	if (magic != COREWAR_EXEC_MAGIC)
	{
		free(bytecode);
		return (-1);
	}
	return (0);
}

int			get_bytecode_size(unsigned char *bytecode, int i, t_champ *champ)
{
	int		code_size;
	size_t	c;

	c = 0;
	code_size = 0x0;
	while (c < 4)
	{
		code_size <<= 8;
		code_size |= bytecode[i];
		i++;
		c++;
	}
	champ->code_size = code_size;
	return (i);
}
