#include "vm.h"

static	int	all_bytes = 0;

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
		return (-1);
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

int			get_name_comment_exec_code(t_champ *champ, unsigned char *bytecode)
{
	size_t	i;
	size_t	j;
	size_t	code_size;
	size_t	tmp;

	i = MAGIC_NUM_B;
	code_size = 0;
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
	// tmp = i;
	// while (tmp < all_bytes)
	// {
	// 	tmp++;
	// 	code_size++;
	// }
	// if (code_size != champ->code_size)
	// 	return (-2);
	j = 0;
	while (j < champ->code_size && i < FILE_SIZE)
		champ->code[j++] = bytecode[i++];
	champ->code[j] = '\0';
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
			all_bytes++;
		}
		i++;
	}
	if (i > FILE_SIZE)
	{
		i -= FILE_SIZE;
		ft_fprintf(2, "Error: File %s has too large a code (%d bytes > %d bytes)\n",
			 file, i + CHAMP_MAX_SIZE, CHAMP_MAX_SIZE);
		free(buf);
		return (NULL);
	}
	return (buf);
}

int		parse_bytecode(t_champ *champ, char *file)
{
	unsigned char	*bytecode;
	int				err;

	if ((bytecode = read_bytecode(champ, file)) == NULL)
		return (-2);
	err = 0;
	err = get_name_comment_exec_code(champ, bytecode);
	// if (err == -2)
	// {
	// 	ft_fprintf(2, "Error: file %s has a code size that differ from what its header says\n", file);
	// 	free(bytecode);
	// 	return (-2);
	// }
	err = check_magic_header(bytecode, champ);
	free(bytecode);
	// if (err == -1)
		// ft_fprintf(2, "Error: file %s has an invalid header\n", file);
	// if (err != 0)
		// return (-2);
	return (1);
}
