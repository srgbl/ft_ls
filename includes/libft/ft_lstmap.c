/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:08:07 by slindgre          #+#    #+#             */
/*   Updated: 2019/01/17 16:22:07 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*list;

	if (!lst)
		return (NULL);
	list = f(lst);
	res = list;
	while (lst->next)
	{
		if (!(list->next = f(lst->next)))
		{
			free(list->next);
			return (NULL);
		}
		lst = lst->next;
		list = list->next;
	}
	return (res);
}
