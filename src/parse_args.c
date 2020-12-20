/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:35:28 by gloras-t          #+#    #+#             */
/*   Updated: 2020/12/20 03:10:39 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	если первый символ "-" то отдаем этой функции
*/

int		parse_options(char *arg, uint8_t *options)
{
	int	ind;
	int	i;

	i = 0;
	if (*arg == '-')
		return (-2);
	while (*arg)
	{
		ind = ft_strchrind(OPTIONS, *arg);
		if (ind == -1)
			return (i + 1);
		*options |= 1 << ind;
		if (*arg == 't')
			*options &= ~OPT_UPPER_S;
		if (*arg == 'S')
			*options &= ~OPT_LOWER_T;
		arg++;
		i++;
	}
	return (-1);
}

void	parse_args(int argc, char *argv[], t_list **paths, uint8_t *options)
{
	int	i;
	int	res;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 1 && argv[i][0] == '-')
		{
			if ((res = parse_options(argv[i] + 1, options)) != -1)
			{
				if (res == -2)
					ft_printf("ft_ls: unrecognized option '%s'\n", argv[i]);
				else
					ft_printf("ft_ls: invalid option -- '%c'\n", argv[i][res]);
				ft_printf("usage: ./ft_ls [-%s] [file ...]\n", OPTIONS);
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
}
