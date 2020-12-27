/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:35:28 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/27 17:49:41 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	combine_options(char *arg, uint16_t *options)
{
	if (*arg == 't')
		*options &= ~OPT_UPPER_S;
	if (*arg == 'S')
		*options &= ~OPT_LOWER_T;
	if (*arg == 'm')
		*options &= ~OPT_LOWER_L;
	if (*arg == 'l')
		*options &= ~OPT_ONE;
	if (*arg == 'l' || *arg == '1' || *arg == 'g')
		*options &= ~OPT_LOWER_M;
	if (*arg == 'm')
		*options &= ~OPT_LOWER_L;
	if (*arg == 'g')
		*options |= OPT_LOWER_L;
}

int			parse_options(char *arg, uint16_t *options)
{
	int	ind;
	int	i;

	i = 0;
	if (*arg == '-')
	{
		if (ft_strlen(arg) > 1)
			return (-2);
		*options |= OPT_ONLY_FILES;
		return (-1);
	}
	while (*arg)
	{
		ind = ft_strchrind(OPTIONS, *arg);
		if (ind == -1)
			return (i + 1);
		*options |= 1 << ind;
		combine_options(arg, options);
		arg++;
		i++;
	}
	return (-1);
}

void		parse_args(int argc, char *a[], t_list **paths, uint16_t *opt)
{
	int	i;
	int	r;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(a[i]) > 1 && a[i][0] == '-' && !(*opt & OPT_ONLY_FILES))
		{
			if ((r = parse_options(a[i] + 1, opt)) != -1)
			{
				if (r == -2)
					ft_printf("ft_ls: unrecognized option '%s'\n%_", a[i], 2);
				else
					ft_printf("ft_ls: invalid option -- '%c'\n%_", a[i][r], 2);
				ft_printf("usage: ./ft_ls [-%s] [file ...]\n%_", OPTIONS, 2);
				ft_lstdel(paths, ft_lst_free_elem);
				exit(2);
			}
		}
		else
			ft_lstadd_back(paths, a[i], ft_strlen(a[i]) + 1);
		i++;
	}
	if (ft_lstsize(*paths) == 0)
		ft_lstadd_back(paths, ".", 2);
}
