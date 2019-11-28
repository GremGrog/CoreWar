/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytecode_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:47:22 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/11/28 12:59:53 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static	int	g_all_bytes = 0;

int				get_exec_code(size_t i, t_champ *champ, unsigned char *bytecode)
{
	size_t	tmp;
	size_t	code_size;
	size_t	j;

	tmp = i;
	code_size = 0;
	j = 0;
	while (tmp < g_all_bytes)
	{
		tmp++;
		code_size++;
	}
	if (code_size != champ->code_size)
	{
		free(bytecode);
		return (-1);
	}
	while (j < champ->code_size && i < g_all_bytes)
		champ->code[j++] = bytecode[i++];
	champ->code[j] = '\0';
	return (0);
}

int				get_name_comment_exec_code(t_champ *champ, \
											unsigned char *bytecode)
{
	size_t	i;
	size_t	j;

	i = MAGIC_NUM_B;
	champ->name = ft_memalloc((size_t)PROG_NAME_LENGTH + 1);
	champ->comment = ft_memalloc((size_t)COMMENT_LENGTH + 1);
	j = 0;
	while (j < PROG_NAME_LENGTH)
		champ->name[j++] = bytecode[i++];
	champ->name[j] = '\0';
	j = 0;
	i = scip_null_border(i);
	i = get_bytecode_size(bytecode, i, champ);
	while (j < COMMENT_LENGTH)
		champ->comment[j++] = bytecode[i++];
	champ->comment[j] = '\0';
	i = scip_null_border(i);
	champ->code = (unsigned char*)malloc(sizeof(unsigned char) \
												* champ->code_size + 1);
	if ((get_exec_code(i, champ, bytecode)) == -1)
		return (-1);
	g_all_bytes = 0;
	return (0);
}

unsigned char	*read_bytecode(t_champ *champ, char *file)
{
	int					fd;
	unsigned char		byte;
	unsigned char		*buf;
	int					ret;
	size_t				i;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	buf = (unsigned char*)malloc(sizeof(unsigned char) * FILE_SIZE);
	byte = 0;
	while ((ret = read(fd, &byte, 1)) > 0)
	{
		if (i < FILE_SIZE)
		{
			buf[i] = byte;
			g_all_bytes++;
		}
		i++;
	}
	if ((check_file_size(i, file, buf)) == -1)
		return (NULL);
	return (buf);
}

int				parse_bytecode(t_champ *champ, char *file)
{
	unsigned char	*bytecode;
	int				err;

	if ((bytecode = read_bytecode(champ, file)) == NULL)
		return (-2);
	err = 0;
	if ((err = check_magic_header(bytecode, champ)) == -1)
	{
		ft_fprintf(2, "Error: file %s has an invalid header\n", file);
		return (-2);
	}
	if ((err = get_name_comment_exec_code(champ, bytecode)) == -1)
	{
		ft_fprintf(2, "Error: \
		file %s has a code size that differ from what its header says\n", file);
		return (-2);
	}
	free(bytecode);
	return (1);
}
