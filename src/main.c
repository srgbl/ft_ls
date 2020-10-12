/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:56:02 by gloras-t          #+#    #+#             */
/*   Updated: 2020/10/12 23:57:17 by slindgre         ###   ########.fr       */
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
	if (verify_paths(paths, &dirs, &files, options) > 0)
		options |= OPT_NEW_LINE;
	ft_lstdel(&paths, ft_lst_free_elem);
	sort_list(&dirs, options);
	sort_list(&files, options);
	if (print_files(files, options | OPT_LOWER_A) > 0)
		options |= OPT_NEW_LINE;
	ft_lstdel(&files, ft_lst_free_file);
	print_dirs(dirs, options, 0);
	ft_lstdel(&dirs, ft_lst_free_file);
	return (0);
}
