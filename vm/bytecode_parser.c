#include "vm.h"

int			check_magic_header(unsigned char *bytecode)
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

int			check_bytecode_size(unsigned char *bytecode, int i, t_champ *champ)
{
	int		code_size;
	size_t	c;

	c = 0;
	code_size = 0x0;
	while (c < MAGIC_NUM_B)
	{
		code_size <<= 8;
		code_size |= bytecode[i];
		i++;
		c++;
	}
	if (code_size > CHAMP_MAX_SIZE)
	{
		//free all !!!!!!!!!!!!!!!!!!!!!!!!!
		ft_errno(4);
		return (-1);
	}
	champ->code_size = code_size;
	return (i);
}

int			get_name_comment_exec_code(t_champ *champ, unsigned char *bytecode)
{
	size_t	i;
	size_t	j;
	size_t	code_size;

	i = MAGIC_NUM_B;
	champ->name = ft_memalloc((size_t)PROG_NAME_LENGTH + 1);
	champ->comment = ft_memalloc((size_t)COMMENT_LENGTH + 1);
	j = 0;
	while (j < PROG_NAME_LENGTH)
		champ->name[j++] = bytecode[i++];
	champ->name[j] = '\0';
	j = 0;
	i = scip_null_border(i);
	if ((i = check_bytecode_size(bytecode, i, champ)) == -1)
		return (-1);
	while (j < COMMENT_LENGTH)
		champ->comment[j++] = bytecode[i++];
	champ->comment[j] = '\0';
	i = scip_null_border(i);
	champ->code = (unsigned char*)malloc(sizeof(unsigned char) \
												* champ->code_size + 1);
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
			buf[i] = byte;
		if (i >= FILE_SIZE)
		{
			ft_printf("%s\n", "error, too much code");
			free(buf);
			break ;
		}
		i++;
	}
	return (buf);
}

int		parse_bytecode(t_champ *champ, char *file)
{
	unsigned char	*bytecode;

	if ((bytecode = read_bytecode(champ, file)) == NULL)
		return (-2);
	if (check_magic_header(bytecode) == -1)
		ft_errno(3);
	get_name_comment_exec_code(champ, bytecode);
	free(bytecode);
	return (1);
}
