/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:16:38 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/12/01 14:35:54 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			check_num(char *arg)
{
	size_t	i;

	i = 0;
	while (arg[i])
	{
		if (!(arg[i] >= '1' && arg[i] <= '9'))
		{
			ft_errno(2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int			parse_flags_v2(char **a, int i)
{
	int		j;
	int		err;

	j = 0;
	err = 0;
	if (ft_strcmp(a[i], "-dump") == 0 && a[i + 1]
	&& (a[i + 1][j] >= '0' && a[i + 1][j] <= '9'))
	{
		i++;
		g_flags->dump = ft_atoi(a[i]);
	}
	else if (ft_strcmp(a[i], "-n") == 0 && a[i + 1]
	&& ((err = check_num(a[i + 1]))) == 0)
	{
		i++;
		g_flags->n = ft_atoi(a[i]);
	}
	else
	{
		if (err == 0)
			ft_errno(7);
		return (-1);
	}
	return (i);
}

int			parse_flags(char **a, int i)
{
	int		j;

	j = 0;
	if (ft_strcmp(a[i], "-v") == 0 && a[i + 1]
	&& (a[i + 1][j] >= '0' && a[i + 1][j] <= '9'))
	{
		i++;
		g_flags->v = ft_atoi(a[i]);
	}
	else if (ft_strcmp(a[i], "-i") == 0)
		g_flags->i = 1;
	else if (ft_strcmp(a[i], "-a") == 0)
		g_flags->a = 1;
	else
		return (parse_flags_v2(a, i));
	return (i);
}

t_champ		*parse_cycle(int i, int c, t_champ *champs, char **a)
{
	while (i < c)
	{
		if (get_file_name(a[i], ".cor") == 1)
		{
			if ((add_champion(a[i], &champs)) == -2)
				return (NULL);
		}
		else if (*a[i] == '-')
		{
			if ((i = parse_flags(a, i)) == -1)
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

t_champ		*parse_args(int c, char **a)
{
	int		i;
	t_champ	*champs;

	init_flags_struct();
	champs = NULL;
	i = 1;
	champs = parse_cycle(i, c, champs, a);
	return (champs);
}
