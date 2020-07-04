/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:56:02 by gloras-t          #+#    #+#             */
/*   Updated: 2020/07/04 12:56:36 by gloras-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;
	(void)envp;
	// char *user = get_env_by_name(envp, USER);
	// println(user);
	// free(user);
	// print_visible_files_in_dir(".");
	get_file_stat(argv[1]);
	return (0);
}
