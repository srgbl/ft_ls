/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:56:02 by gloras-t          #+#    #+#             */
/*   Updated: 2020/07/05 01:50:11 by gloras-t         ###   ########.fr       */
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
	// char *user = get_env_by_name(envp, USER);
	// println(user);
	// free(user);
	// print_visible_files_in_dir(".");
	t_file_ll *file_list = init_file_ll();
	set_file(".", file_list);
	return (0);
}
