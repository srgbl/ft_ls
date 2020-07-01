/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_in_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:15:19 by gloras-t          #+#    #+#             */
/*   Updated: 2019/05/17 19:44:12 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_in_line(char c, char *line)
{
	if (line)
	{
		while (*line)
		{
			if (*line == c)
				return (1);
			line++;
		}
	}
	return (0);
}
