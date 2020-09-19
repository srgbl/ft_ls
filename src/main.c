/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:56:02 by gloras-t          #+#    #+#             */
/*   Updated: 2020/08/24 02:46:27 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	uint8_t	options;
	t_list	*paths;
	t_list	*files;

	paths = NULL;
	files = NULL;
	options = 0;
	parse_args(argc, argv, &paths, &options);
	verify_paths(&paths, &files, options);
	sort_list(&paths, sort_paths);
	//ft_lstprint(paths);
	sort_list(&files, sort_files);
	//ft_lstiter(files, print_file_name);
	
	ft_lstdel(&paths, ft_lst_free_elem);
	ft_lstdel(&files, ft_lst_free_file);
	return (0);
}
