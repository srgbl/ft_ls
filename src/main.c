/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 20:56:02 by gloras-t          #+#    #+#             */
/*   Updated: 2020/07/03 22:49:43 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv, char **envp)
{
	char	*user;
	uint8_t	options;
	t_list	*paths;

	paths = NULL;
	options = 0;
	parse_args(argc, argv, &options, &paths);
	// ft_printf("%08b\n", options);
	// ft_lstiter(paths, print_list);
	user = get_env_by_name(envp, USER);
	free(user);
	ft_lstdel(&paths, ft_bzero);
	return (0);
}
