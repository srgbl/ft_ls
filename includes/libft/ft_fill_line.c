/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 01:00:13 by gloras-t          #+#    #+#             */
/*   Updated: 2019/05/17 19:44:20 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fill_line(int length, char c)
{
	int		i;
	char	*str;

	str = ft_strnew(length);
	i = 0;
	while (i < length)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
