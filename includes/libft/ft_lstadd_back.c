/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:47:06 by slindgre          #+#    #+#             */
/*   Updated: 2019/08/18 19:17:21 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, void const *content, size_t content_size)
{
	t_list *new_last;
	t_list *temp;

	if (list && (new_last = ft_lstnew(content, content_size)))
	{
		if (!*list)
			*list = new_last;
		else
		{
			temp = *list;
			while (temp->next)
				temp = temp->next;
			temp->next = new_last;
		}
	}
}
