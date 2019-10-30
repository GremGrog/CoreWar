#include "vm.h"

size_t			scip_null_border(size_t i)
{
	size_t	c;

	c = 0;
	while (c++ < NULL_B)
		i++;
	return (i);
}

int			ft_rstrcmp(const char *str1, const char *str2)
{
	size_t	index;
	size_t  len1;
	size_t  len2;

	index = 0;
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (!str1 || !str2)
		return (0);
	while ((str1[len1 - index] || str2[len2 - index]))
	{
		if (str1[len1 - index] != str2[len2 - index])
		{
			return ((int)((unsigned char)str1[len1 - index] - \
			(unsigned char)str2[len2 - index]));
		}
		index++;
	}
	return (0);
}