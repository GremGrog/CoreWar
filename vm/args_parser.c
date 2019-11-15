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
// else if (ft_rstrcmp(a[i], "-n") == 1)
// 		{
// 			if ((n = check_num(a[++i], c)) == -2)
// 			{
// 				delete_champs(champs);
// 				return (NULL);
// 			}
// 		}

int			parse_flags(char **a, int i)
{
	int		j;

	g_flags = (t_flags*)malloc(sizeof(t_flags));
	g_flags->dump = 0;
	g_flags->n = 0;
	g_flags->v = 0;
	j = 0;
	while (a[i])
	{
		if (ft_strcmp(a[i], "-v") == 0)
		{
			i++;
			if (a[i][j] >= '1' && a[i][j] <= '9')
				g_flags->v = ft_atoi(a[i]);
			else
				ft_errno(2);
		}
		else
			break ;
	}
	return (i);
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
		else if (*a[i] == '-')
		{
			i = parse_flags(a, i);
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