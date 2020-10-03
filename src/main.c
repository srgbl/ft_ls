/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:56:02 by gloras-t          #+#    #+#             */
/*   Updated: 2020/10/04 02:20:10 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	uint8_t	options;
	t_list	*paths;
	t_list	*dirs;
	t_list	*files;

	paths = NULL;
	dirs = NULL;
	files = NULL;
	options = 0;
	parse_args(argc, argv, &paths, &options);
	verify_paths(paths, &dirs, &files, options);
	ft_lstdel(&paths, ft_lst_free_elem);
	sort_list(&dirs, sort_files);
	sort_list(&files, sort_files);
	
	ft_lstdel(&dirs, ft_lst_free_file);
	ft_lstdel(&files, ft_lst_free_file);
	return (0);
}
