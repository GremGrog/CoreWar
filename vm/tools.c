#include "vm.h"

size_t			scip_null_border(size_t i)
{
	size_t	c;

	c = 0;
	while (c++ < NULL_B)
		i++;
	return (i);
}

int			ft_rstrcmp(const char *str, const char *substr)
{
	size_t  strlen;
	size_t  sublen;

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