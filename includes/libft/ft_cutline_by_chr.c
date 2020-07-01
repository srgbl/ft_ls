/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cutline_by_chr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gloras-t <gloras-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:44:59 by gloras-t          #+#    #+#             */
/*   Updated: 2019/08/17 23:10:10 by gloras-t         ###   ########.fr       */
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
