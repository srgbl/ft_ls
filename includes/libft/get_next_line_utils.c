/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 23:32:59 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/26 16:47:45 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file_list	*create_file(int fd)
{
	t_file_list	*file;

	file = malloc(sizeof(t_file_list));
	file->fd = fd;
	file->rest_of_line = ft_strdup("");
	file->next = NULL;
	return (file);
}

void		add_file(t_file_list **head, t_file_list *new)
{
	new->next = (*head);
	(*head) = new;
}

t_file_list	*get_file_by_fd(t_file_list **head, int fd)
{
	t_file_list	*ptr;

	ptr = (*head);
	while (ptr)
	{
		if (ptr->fd == fd)
			return (ptr);
		ptr = ptr->next;
	}
	free(ptr);
	return (NULL);
}
