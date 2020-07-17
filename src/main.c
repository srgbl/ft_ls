/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:56:02 by gloras-t          #+#    #+#             */
/*   Updated: 2020/07/06 22:17:00 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_ll	*init_file_ll()
{
	t_file_ll	*list;

	list = (t_file_ll*)malloc(sizeof(t_file_ll));
	if (!list)
		return (NULL);
	list->file = NULL;
	list->next = NULL;
	return (list);
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;
	return (0);
}
