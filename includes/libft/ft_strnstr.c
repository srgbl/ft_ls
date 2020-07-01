/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slindgre <slindgre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 19:28:19 by slindgre          #+#    #+#             */
/*   Updated: 2018/12/05 15:49:04 by slindgre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t i;
	size_t s;

	i = 0;
	s = 0;
	if (!*needle)
		return ((char*)str);
	while (str[i] != '\0' && i < len)
	{
		s = 0;
		while (str[i + s] == needle[s] && (i + s) < len)
		{
			if (needle[s + 1] == '\0')
				return ((char*)str + i);
			s++;
		}
		i++;
	}
	return (NULL);
}
