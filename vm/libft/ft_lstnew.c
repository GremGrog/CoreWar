/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 21:36:26 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/09/06 19:41:46 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l;

	if (!(l = (t_list *)malloc(sizeof(t_list) * (content_size + 1))))
		return (NULL);
	else
	{
		if (!content)
		{
			l->content = NULL;
			l->content_size = 0;
		}
		else
		{
			l->content = (t_list*)malloc(sizeof(t_list) * (content_size + 1));
			if (!(l->content))
			{
				free(l);
				return (NULL);
			}
			ft_memcpy(l->content, content, content_size + 1);
			l->content_size = content_size;
		}
	}
	l->next = NULL;
	return (l);
}
