/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:34:20 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/12/01 14:34:37 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			ft_get_char_i_rev(char *str, char c)
{
	int i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == c)
			return (i);
		i--;
	}
	return (-1);
}

int			get_file_name(char *file_name, char *ext)
{
	int i;

	i = ft_get_char_i_rev(file_name, '.');
	if (i == -1 || ft_strlen(file_name) < ft_strlen(ext) ||
		ft_strlen(ext) < 2 || ext[0] != '.')
		return (-1);
	if (ft_strcmp(&(file_name[i]), ext) != 0)
		return (-1);
	return (1);
}
