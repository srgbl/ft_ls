/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:17:19 by gloras-t          #+#    #+#             */
/*   Updated: 2019/05/17 19:44:24 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_char(char *str, char c, int index)
{
	char	*tmp;
	int		i;
	int		length;

	length = (str) ? (int)ft_strlen(str) : 0;
	tmp = ft_strnew(length + 1);
	i = 0;
	tmp[index] = c;
	while (i < index)
	{
		tmp[i] = str[i];
		i++;
	}
	while (index < length)
	{
		tmp[index + 1] = str[index];
		index++;
	}
	return (tmp);
}
