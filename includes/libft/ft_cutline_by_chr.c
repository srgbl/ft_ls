/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutline_by_chr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:44:59 by slindgre          #+#    #+#             */
/*   Updated: 2020/12/26 16:45:56 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cutline_by_chr(char **src, int c)
{
	int		i;
	char	*str;
	char	*tmp;

	if (src)
	{
		if ((i = ft_strchrind(*src, c)) > -1)
		{
			tmp = *src;
			str = ft_strsub(*src, 0, i);
			*src = ft_strsub(*src, i + 1, ft_strlen(*src));
			ft_strdel(&tmp);
			return (str);
		}
	}
	return (NULL);
}
