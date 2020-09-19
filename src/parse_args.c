/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:35:28 by gloras-t          #+#    #+#             */
/*   Updated: 2020/08/23 18:39:43 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	если первый символ "-" то отдаем этой функции
*/

static int	parse_options(char *arg, uint8_t *options)
{
	int	ind;

	while (*arg)
	{
		ind = ft_strchrind(OPTIONS, *arg);
		if (ind == -1)
			return (-1);
		*options |= 1 << ind;
		arg++;
	}
	return (0);
}

int			parse_args(int argc, char *argv[], t_list **paths, uint8_t *options)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 1 && argv[i][0] == '-')
		{
			if (parse_options(argv[i] + 1, options) == -1)
			{
				ft_printf("ft_ls: invalid option -- '%c'\n");
				ft_lstdel(paths, ft_lst_free_elem);
				exit(-1);
			}
		}
		else
			ft_lstadd_back(paths, argv[i], ft_strlen(argv[i]) + 1);
		i++;
	}
	if (ft_lstsize(*paths) == 0)
		ft_lstadd_back(paths, ".", 2);
	return (0);
}
