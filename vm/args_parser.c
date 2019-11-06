#include "vm.h"

int			check_num(char *arg, int c)
{
	size_t	i;
	int		n;

	i = 0;
	n = -1;
	if (arg[i] >= '1' && arg[i] <= '9')
	{
		if ((n = ft_atoi(arg)) > c - 3)
		{
			n = -2;
			ft_errno(6);
		}
	}
	else
	{
		ft_errno(6);
		n = -2;
	}
	return (n);
}

t_champ		*parse_args(int c, char **a)
{
	int		i;
	int		n;
	t_champ	*champs;

	champs = NULL;
	i = 1;
	n = -1;
	while (i < c)
	{
		if (ft_rstrcmp(a[i], ".cor") == 1)
			n = add_champion(a[i], n, &champs);
		else if (ft_rstrcmp(a[i], "-n") == 1)
		{
			if ((n = check_num(a[++i], c)) == -2)
			{
				delete_champs(champs);
				return (NULL);
			}
		}
		else
		{
			ft_errno(2);
			return (NULL);
		}
		i++;
	}
	return (champs);
}